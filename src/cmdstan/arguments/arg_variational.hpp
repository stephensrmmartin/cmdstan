#ifndef CMDSTAN_ARGUMENTS_VARIATIONAL_HPP
#define CMDSTAN_ARGUMENTS_VARIATIONAL_HPP

#include <cmdstan/arguments/arg_tolerance.hpp>
#include <cmdstan/arguments/arg_variational_adapt.hpp>
#include <cmdstan/arguments/arg_variational_algo.hpp>
#include <cmdstan/arguments/arg_variational_eta.hpp>
#include <cmdstan/arguments/arg_variational_eval_window.hpp>
#include <cmdstan/arguments/arg_variational_window_size.hpp>
#include <cmdstan/arguments/arg_variational_rhat_cut.hpp>
#include <cmdstan/arguments/arg_variational_mcse_cut.hpp>
#include <cmdstan/arguments/arg_variational_ess_cut.hpp>
#include <cmdstan/arguments/arg_variational_num_chains.hpp>
#include <cmdstan/arguments/arg_variational_iter.hpp>
#include <cmdstan/arguments/arg_variational_num_samples.hpp>
#include <cmdstan/arguments/arg_variational_output_samples.hpp>
#include <cmdstan/arguments/arg_variational_rank.hpp>
#include <cmdstan/arguments/categorical_argument.hpp>
#include <stan/services/experimental/advi/defaults.hpp>

namespace cmdstan {
using stan::services::experimental::advi::elbo_samples;
using stan::services::experimental::advi::eval_elbo;
using stan::services::experimental::advi::gradient_samples;
using stan::services::experimental::advi::output_draws;
using stan::services::experimental::advi::tol_rel_obj;

class arg_variational : public categorical_argument {
 public:
  arg_variational() {
    _name = "variational";
    _description = "Variational inference";

    _subarguments.push_back(new arg_variational_algo());
    _subarguments.push_back(new arg_variational_iter());
    _subarguments.push_back(new arg_variational_rank());
    _subarguments.push_back(new arg_variational_num_samples(
        "grad_samples", gradient_samples::description().c_str(),
        gradient_samples::default_value()));
    _subarguments.push_back(new arg_variational_num_samples(
        "elbo_samples", elbo_samples::description().c_str(),
        elbo_samples::default_value()));
    _subarguments.push_back(new arg_variational_eta());
    _subarguments.push_back(new arg_variational_adapt());
    _subarguments.push_back(new arg_variational_eval_window());
    _subarguments.push_back(new arg_variational_window_size());
    _subarguments.push_back(new arg_variational_rhat_cut());
    _subarguments.push_back(new arg_variational_mcse_cut());
    _subarguments.push_back(new arg_variational_ess_cut());
    _subarguments.push_back(new arg_variational_num_chains());
    _subarguments.push_back(new arg_variational_output_samples(
        "output_samples", output_draws::description().c_str(),
        output_draws::default_value()));
  }
};

}  // namespace cmdstan
#endif
