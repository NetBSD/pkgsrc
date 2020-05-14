$NetBSD: patch-gr-qtgui_lib_histogram__sink__f__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-qtgui/lib/histogram_sink_f_impl.cc.orig	2020-05-10 01:47:35.846954976 +0000
+++ gr-qtgui/lib/histogram_sink_f_impl.cc
@@ -72,7 +72,7 @@ namespace gr {
       // setup PDU handling input port
       message_port_register_in(pmt::mp("in"));
       set_msg_handler(pmt::mp("in"),
-                      boost::bind(&histogram_sink_f_impl::handle_pdus, this, _1));
+                      boost::bind(&histogram_sink_f_impl::handle_pdus, this, boost::placeholders::_1));
 
       // +1 for the PDU buffer
       for(int i = 0; i < d_nconnections+1; i++) {
