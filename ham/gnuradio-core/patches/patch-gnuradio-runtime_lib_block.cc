$NetBSD: patch-gnuradio-runtime_lib_block.cc,v 1.1 2020/05/09 15:17:51 joerg Exp $

--- gnuradio-runtime/lib/block.cc.orig	2020-05-08 23:51:09.426889790 +0000
+++ gnuradio-runtime/lib/block.cc
@@ -60,7 +60,7 @@ namespace gr {
   {
     global_block_registry.register_primitive(alias(), this);
     message_port_register_in(d_system_port);
-    set_msg_handler(d_system_port, boost::bind(&block::system_handler, this, _1));
+    set_msg_handler(d_system_port, boost::bind(&block::system_handler, this, boost::placeholders::_1));
 
     configure_default_loggers(d_logger, d_debug_logger, symbol_name());
   }
