$NetBSD: patch-gr-blocks_lib_repeat__impl.cc,v 1.1 2020/05/09 15:17:51 joerg Exp $

--- gr-blocks/lib/repeat_impl.cc.orig	2020-05-09 00:14:31.767691624 +0000
+++ gr-blocks/lib/repeat_impl.cc
@@ -45,7 +45,7 @@ namespace gr {
     {
         message_port_register_in(pmt::mp("interpolation"));
         set_msg_handler(pmt::mp("interpolation"),
-                boost::bind(&repeat_impl::msg_set_interpolation, this, _1));
+                boost::bind(&repeat_impl::msg_set_interpolation, this, boost::placeholders::_1));
     }
 
     void
