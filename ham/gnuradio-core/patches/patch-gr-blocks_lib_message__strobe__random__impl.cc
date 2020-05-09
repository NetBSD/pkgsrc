$NetBSD: patch-gr-blocks_lib_message__strobe__random__impl.cc,v 1.3 2020/05/09 15:17:51 joerg Exp $

--- gr-blocks/lib/message_strobe_random_impl.cc.orig	2020-05-09 00:14:08.662748468 +0000
+++ gr-blocks/lib/message_strobe_random_impl.cc
@@ -68,7 +68,7 @@ namespace gr {
 
       message_port_register_in(pmt::mp("set_msg"));
       set_msg_handler(pmt::mp("set_msg"),
-                      boost::bind(&message_strobe_random_impl::set_msg, this, _1));
+                      boost::bind(&message_strobe_random_impl::set_msg, this, boost::placeholders::_1));
     }
 
     float message_strobe_random_impl::next_delay(){
