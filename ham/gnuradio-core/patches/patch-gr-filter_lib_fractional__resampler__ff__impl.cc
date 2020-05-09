$NetBSD: patch-gr-filter_lib_fractional__resampler__ff__impl.cc,v 1.1 2020/05/09 15:17:51 joerg Exp $

--- gr-filter/lib/fractional_resampler_ff_impl.cc.orig	2020-05-09 00:31:06.387390287 +0000
+++ gr-filter/lib/fractional_resampler_ff_impl.cc
@@ -55,7 +55,7 @@ namespace gr {
 
       message_port_register_in(pmt::intern("msg_in"));
       set_msg_handler(pmt::intern("msg_in"), boost::bind(
-              &fractional_resampler_ff_impl::handle_msg, this, _1));
+              &fractional_resampler_ff_impl::handle_msg, this, boost::placeholders::_1));
     }
 
     fractional_resampler_ff_impl::~fractional_resampler_ff_impl()
