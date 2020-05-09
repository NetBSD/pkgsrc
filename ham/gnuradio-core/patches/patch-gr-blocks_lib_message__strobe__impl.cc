$NetBSD: patch-gr-blocks_lib_message__strobe__impl.cc,v 1.3 2020/05/09 15:17:51 joerg Exp $

--- gr-blocks/lib/message_strobe_impl.cc.orig	2020-05-09 00:13:08.349836282 +0000
+++ gr-blocks/lib/message_strobe_impl.cc
@@ -58,7 +58,7 @@ namespace gr {
 
       message_port_register_in(pmt::mp("set_msg"));
       set_msg_handler(pmt::mp("set_msg"),
-                      boost::bind(&message_strobe_impl::set_msg, this, _1));
+                      boost::bind(&message_strobe_impl::set_msg, this, boost::placeholders::_1));
     }
 
     message_strobe_impl::~message_strobe_impl()
