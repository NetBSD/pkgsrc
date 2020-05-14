$NetBSD: patch-gr-qtgui_lib_const__sink__c__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-qtgui/lib/const_sink_c_impl.cc.orig	2020-05-10 01:47:27.704318621 +0000
+++ gr-qtgui/lib/const_sink_c_impl.cc
@@ -69,7 +69,7 @@ namespace gr {
       // setup PDU handling input port
       message_port_register_in(pmt::mp("in"));
       set_msg_handler(pmt::mp("in"),
-                      boost::bind(&const_sink_c_impl::handle_pdus, this, _1));
+                      boost::bind(&const_sink_c_impl::handle_pdus, this, boost::placeholders::_1));
 
       for(int i = 0; i < d_nconnections; i++) {
 	d_residbufs_real.push_back((double*)volk_malloc(d_buffer_size*sizeof(double),
