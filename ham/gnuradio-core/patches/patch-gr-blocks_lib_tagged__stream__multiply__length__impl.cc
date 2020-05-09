$NetBSD: patch-gr-blocks_lib_tagged__stream__multiply__length__impl.cc,v 1.1 2020/05/09 15:17:51 joerg Exp $

--- gr-blocks/lib/tagged_stream_multiply_length_impl.cc.orig	2020-05-09 00:14:36.233242762 +0000
+++ gr-blocks/lib/tagged_stream_multiply_length_impl.cc
@@ -48,7 +48,7 @@ namespace gr {
       set_relative_rate(1);
       message_port_register_in(pmt::intern("set_scalar"));
       set_msg_handler(pmt::intern("set_scalar"),
-        boost::bind(&tagged_stream_multiply_length_impl::set_scalar_pmt, this, _1));
+        boost::bind(&tagged_stream_multiply_length_impl::set_scalar_pmt, this, boost::placeholders::_1));
     }
 
     tagged_stream_multiply_length_impl::~tagged_stream_multiply_length_impl()
