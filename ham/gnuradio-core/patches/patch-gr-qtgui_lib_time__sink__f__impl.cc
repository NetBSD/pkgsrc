$NetBSD: patch-gr-qtgui_lib_time__sink__f__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-qtgui/lib/time_sink_f_impl.cc.orig	2020-05-10 01:47:48.672097068 +0000
+++ gr-qtgui/lib/time_sink_f_impl.cc
@@ -73,7 +73,7 @@ namespace gr {
       // setup PDU handling input port
       message_port_register_in(pmt::mp("in"));
       set_msg_handler(pmt::mp("in"),
-                      boost::bind(&time_sink_f_impl::handle_pdus, this, _1));
+                      boost::bind(&time_sink_f_impl::handle_pdus, this, boost::placeholders::_1));
 
       // +1 for the PDU buffer
       for(int n = 0; n < d_nconnections+1; n++) {
