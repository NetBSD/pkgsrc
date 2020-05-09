$NetBSD: patch-gr-filter_lib_fractional__resampler__cc__impl.cc,v 1.1 2020/05/09 15:17:51 joerg Exp $

--- gr-filter/lib/fractional_resampler_cc_impl.cc.orig	2020-05-09 00:31:08.332613492 +0000
+++ gr-filter/lib/fractional_resampler_cc_impl.cc
@@ -54,7 +54,7 @@ namespace gr {
       set_relative_rate(1.0 / resamp_ratio);
       message_port_register_in(pmt::intern("msg_in"));
       set_msg_handler(pmt::intern("msg_in"), boost::bind(
-              &fractional_resampler_cc_impl::handle_msg, this, _1));
+              &fractional_resampler_cc_impl::handle_msg, this, boost::placeholders::_1));
     }
 
     fractional_resampler_cc_impl::~fractional_resampler_cc_impl()
