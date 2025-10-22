$NetBSD: patch-plugin_x_protocol_stream_decompression__input__stream.h,v 1.1 2025/10/22 07:21:48 jnemeth Exp $

--- plugin/x/protocol/stream/decompression_input_stream.h.orig	2024-07-13 15:30:43.000000000 +0000
+++ plugin/x/protocol/stream/decompression_input_stream.h
@@ -93,7 +93,7 @@ class Decompression_input_stream
     return Skip(count - left);
   }
 
-  google::protobuf::int64 ByteCount() const override {
+  int64_t ByteCount() const override {
     return m_all + m_output_buffer_offset;
   }
 
