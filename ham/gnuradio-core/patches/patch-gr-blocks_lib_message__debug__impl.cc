$NetBSD: patch-gr-blocks_lib_message__debug__impl.cc,v 1.1 2020/05/09 15:17:51 joerg Exp $

--- gr-blocks/lib/message_debug_impl.cc.orig	2020-05-09 00:13:10.692843843 +0000
+++ gr-blocks/lib/message_debug_impl.cc
@@ -102,13 +102,13 @@ namespace gr {
                  io_signature::make(0, 0, 0))
     {
       message_port_register_in(pmt::mp("print"));
-      set_msg_handler(pmt::mp("print"), boost::bind(&message_debug_impl::print, this, _1));
+      set_msg_handler(pmt::mp("print"), boost::bind(&message_debug_impl::print, this, boost::placeholders::_1));
 
       message_port_register_in(pmt::mp("store"));
-      set_msg_handler(pmt::mp("store"), boost::bind(&message_debug_impl::store, this, _1));
+      set_msg_handler(pmt::mp("store"), boost::bind(&message_debug_impl::store, this, boost::placeholders::_1));
 
       message_port_register_in(pmt::mp("print_pdu"));
-      set_msg_handler(pmt::mp("print_pdu"), boost::bind(&message_debug_impl::print_pdu, this, _1));
+      set_msg_handler(pmt::mp("print_pdu"), boost::bind(&message_debug_impl::print_pdu, this, boost::placeholders::_1));
     }
 
     message_debug_impl::~message_debug_impl()
