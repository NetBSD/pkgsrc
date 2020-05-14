$NetBSD: patch-gr-qtgui_lib_sink__c__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-qtgui/lib/sink_c_impl.cc.orig	2020-05-10 01:47:38.139712715 +0000
+++ gr-qtgui/lib/sink_c_impl.cc
@@ -79,7 +79,7 @@ namespace gr {
       message_port_register_out(d_port);
       message_port_register_in(d_port);
       set_msg_handler(d_port,
-                      boost::bind(&sink_c_impl::handle_set_freq, this, _1));
+                      boost::bind(&sink_c_impl::handle_set_freq, this, boost::placeholders::_1));
 
       d_main_gui = NULL;
 
