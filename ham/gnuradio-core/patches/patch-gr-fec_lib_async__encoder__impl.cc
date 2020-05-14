$NetBSD: patch-gr-fec_lib_async__encoder__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-fec/lib/async_encoder_impl.cc.orig	2020-05-10 02:07:18.405428399 +0000
+++ gr-fec/lib/async_encoder_impl.cc
@@ -63,7 +63,7 @@ namespace gr {
       message_port_register_out(d_out_port);
 
       if(d_packed) {
-        set_msg_handler(d_in_port, boost::bind(&async_encoder_impl::encode_packed, this ,_1) );
+        set_msg_handler(d_in_port, boost::bind(&async_encoder_impl::encode_packed, this ,boost::placeholders::_1) );
 
         d_unpack = new blocks::kernel::unpack_k_bits(8);
 
@@ -73,7 +73,7 @@ namespace gr {
 
       }
       else {
-        set_msg_handler(d_in_port, boost::bind(&async_encoder_impl::encode_unpacked, this ,_1) );
+        set_msg_handler(d_in_port, boost::bind(&async_encoder_impl::encode_unpacked, this ,boost::placeholders::_1) );
       }
 
       if(d_packed || (strncmp(d_encoder->get_input_conversion(), "pack", 4) == 0)) {
