$NetBSD: patch-gr-qtgui_lib_time__sink__c__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-qtgui/lib/time_sink_c_impl.cc.orig	2020-05-10 01:46:15.407160673 +0000
+++ gr-qtgui/lib/time_sink_c_impl.cc
@@ -73,7 +73,7 @@ namespace gr {
       // setup PDU handling input port
       message_port_register_in(pmt::mp("in"));
       set_msg_handler(pmt::mp("in"),
-                      boost::bind(&time_sink_c_impl::handle_pdus, this, _1));
+                      boost::bind(&time_sink_c_impl::handle_pdus, this, boost::placeholders::_1));
 
       // +2 for the PDU message buffers
       for(int n = 0; n < d_nconnections+2; n++) {
