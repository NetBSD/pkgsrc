$NetBSD: patch-gr-blocks_lib_copy__impl.cc,v 1.1 2020/05/09 15:17:51 joerg Exp $

--- gr-blocks/lib/copy_impl.cc.orig	2020-05-09 00:11:28.288489868 +0000
+++ gr-blocks/lib/copy_impl.cc
@@ -47,7 +47,7 @@ namespace gr {
     {
       message_port_register_in(pmt::mp("en"));
       set_msg_handler(pmt::mp("en"),
-                      boost::bind(&copy_impl::handle_enable, this, _1));
+                      boost::bind(&copy_impl::handle_enable, this, boost::placeholders::_1));
     }
 
     copy_impl::~copy_impl()
