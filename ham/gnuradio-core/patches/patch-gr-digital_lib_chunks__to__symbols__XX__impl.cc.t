$NetBSD: patch-gr-digital_lib_chunks__to__symbols__XX__impl.cc.t,v 1.1 2020/05/09 15:17:51 joerg Exp $

--- gr-digital/lib/chunks_to_symbols_XX_impl.cc.t.orig	2020-05-09 00:48:48.819019376 +0000
+++ gr-digital/lib/chunks_to_symbols_XX_impl.cc.t
@@ -52,7 +52,7 @@ namespace gr {
       set_msg_handler(
         pmt::mp("set_symbol_table"),
         boost::bind(&@IMPL_NAME@::handle_set_symbol_table,
-                    this, _1));
+                    this, boost::placeholders::_1));
     }
 
     @IMPL_NAME@::~@IMPL_NAME@()
