$NetBSD: patch-gr-digital_lib_protocol__formatter__async__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-digital/lib/protocol_formatter_async_impl.cc.orig	2020-05-10 02:22:36.161047409 +0000
+++ gr-digital/lib/protocol_formatter_async_impl.cc
@@ -55,7 +55,7 @@ namespace gr {
       message_port_register_out(d_pld_port);
 
       set_msg_handler(d_in_port,
-                      boost::bind(&protocol_formatter_async_impl::append, this ,_1) );
+                      boost::bind(&protocol_formatter_async_impl::append, this ,boost::placeholders::_1) );
     }
 
     protocol_formatter_async_impl::~protocol_formatter_async_impl()
