$NetBSD: patch-gr-blocks_lib_nop__impl.cc,v 1.1 2020/05/09 15:17:51 joerg Exp $

--- gr-blocks/lib/nop_impl.cc.orig	2020-05-09 00:14:19.564916271 +0000
+++ gr-blocks/lib/nop_impl.cc
@@ -46,7 +46,7 @@ namespace gr {
     {
       // Arrange to have count_received_msgs called when messages are received.
       message_port_register_in(pmt::mp("port"));
-      set_msg_handler(pmt::mp("port"), boost::bind(&nop_impl::count_received_msgs, this, _1));
+      set_msg_handler(pmt::mp("port"), boost::bind(&nop_impl::count_received_msgs, this, boost::placeholders::_1));
     }
 
     nop_impl::~nop_impl()
