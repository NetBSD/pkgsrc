$NetBSD: patch-gr-qtgui_lib_sink__f__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-qtgui/lib/sink_f_impl.cc.orig	2020-05-10 01:47:40.242558048 +0000
+++ gr-qtgui/lib/sink_f_impl.cc
@@ -79,7 +79,7 @@ namespace gr {
       message_port_register_out(d_port);
       message_port_register_in(d_port);
       set_msg_handler(d_port,
-                      boost::bind(&sink_f_impl::handle_set_freq, this, _1));
+                      boost::bind(&sink_f_impl::handle_set_freq, this, boost::placeholders::_1));
 
       d_main_gui = NULL;
 
