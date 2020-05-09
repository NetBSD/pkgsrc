$NetBSD: patch-gr-analog_lib_sig__source__X__impl.cc.t,v 1.1 2020/05/09 15:17:51 joerg Exp $

--- gr-analog/lib/sig_source_X_impl.cc.t.orig	2020-05-09 00:48:44.893191233 +0000
+++ gr-analog/lib/sig_source_X_impl.cc.t
@@ -55,7 +55,7 @@ namespace gr {
       set_frequency(frequency);
 
       message_port_register_in(pmt::mp("freq"));
-      set_msg_handler(pmt::mp("freq"), boost::bind(&@IMPL_NAME@::set_frequency_msg, this, _1));
+      set_msg_handler(pmt::mp("freq"), boost::bind(&@IMPL_NAME@::set_frequency_msg, this, boost::placeholders::_1));
     }
 
     @IMPL_NAME@::~@IMPL_NAME@()
