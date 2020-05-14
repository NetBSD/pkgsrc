$NetBSD: patch-gr-qtgui_lib_waterfall__sink__c__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-qtgui/lib/waterfall_sink_c_impl.cc.orig	2020-05-10 01:49:02.999982945 +0000
+++ gr-qtgui/lib/waterfall_sink_c_impl.cc
@@ -114,12 +114,12 @@ namespace gr {
       message_port_register_out(d_port);
       message_port_register_in(d_port);
       set_msg_handler(d_port,
-                      boost::bind(&waterfall_sink_c_impl::handle_set_freq, this, _1));
+                      boost::bind(&waterfall_sink_c_impl::handle_set_freq, this, boost::placeholders::_1));
 
       // setup PDU handling input port
       message_port_register_in(pmt::mp("in"));
       set_msg_handler(pmt::mp("in"),
-                      boost::bind(&waterfall_sink_c_impl::handle_pdus, this, _1));
+                      boost::bind(&waterfall_sink_c_impl::handle_pdus, this, boost::placeholders::_1));
     }
 
     waterfall_sink_c_impl::~waterfall_sink_c_impl()
