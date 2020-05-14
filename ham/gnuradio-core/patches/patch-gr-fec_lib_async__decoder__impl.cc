$NetBSD: patch-gr-fec_lib_async__decoder__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-fec/lib/async_decoder_impl.cc.orig	2020-05-10 02:07:16.487899286 +0000
+++ gr-fec/lib/async_decoder_impl.cc
@@ -67,10 +67,10 @@ namespace gr {
 
       if(d_packed) {
         d_pack = new blocks::kernel::pack_k_bits(8);
-        set_msg_handler(d_in_port, boost::bind(&async_decoder_impl::decode_packed, this ,_1));
+        set_msg_handler(d_in_port, boost::bind(&async_decoder_impl::decode_packed, this ,boost::placeholders::_1));
       }
       else {
-        set_msg_handler(d_in_port, boost::bind(&async_decoder_impl::decode_unpacked, this ,_1));
+        set_msg_handler(d_in_port, boost::bind(&async_decoder_impl::decode_unpacked, this ,boost::placeholders::_1));
       }
 
       // The maximum frame size is set by the initial frame size of the decoder.
