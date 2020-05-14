$NetBSD: patch-gr-digital_lib_crc32__async__bb__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-digital/lib/crc32_async_bb_impl.cc.orig	2020-05-10 02:22:32.417304070 +0000
+++ gr-digital/lib/crc32_async_bb_impl.cc
@@ -51,9 +51,9 @@ namespace gr {
       message_port_register_out(d_out_port);
 
       if(check)
-        set_msg_handler(d_in_port, boost::bind(&crc32_async_bb_impl::check, this ,_1) );
+        set_msg_handler(d_in_port, boost::bind(&crc32_async_bb_impl::check, this ,boost::placeholders::_1) );
       else
-        set_msg_handler(d_in_port, boost::bind(&crc32_async_bb_impl::calc, this ,_1) );
+        set_msg_handler(d_in_port, boost::bind(&crc32_async_bb_impl::calc, this ,boost::placeholders::_1) );
     }
 
     crc32_async_bb_impl::~crc32_async_bb_impl()
