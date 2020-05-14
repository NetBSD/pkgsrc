$NetBSD: patch-gr-qtgui_lib_edit__box__msg__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-qtgui/lib/edit_box_msg_impl.cc.orig	2020-05-10 01:47:30.641188810 +0000
+++ gr-qtgui/lib/edit_box_msg_impl.cc
@@ -161,7 +161,7 @@ namespace gr {
       message_port_register_in(pmt::mp("val"));
 
       set_msg_handler(pmt::mp("val"),
-                      boost::bind(&edit_box_msg_impl::set_value, this, _1));
+                      boost::bind(&edit_box_msg_impl::set_value, this, boost::placeholders::_1));
     }
 
     edit_box_msg_impl::~edit_box_msg_impl()
