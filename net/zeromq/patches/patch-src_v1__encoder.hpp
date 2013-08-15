$NetBSD: patch-src_v1__encoder.hpp,v 1.1 2013/08/15 16:29:25 joerg Exp $

--- src/v1_encoder.hpp.orig	2013-08-15 15:50:41.000000000 +0000
+++ src/v1_encoder.hpp
@@ -29,7 +29,7 @@
 namespace zmq
 {
 
-    class i_msg_source;
+    struct i_msg_source;
 
     //  Encoder for 0MQ framing protocol. Converts messages into data stream.
 
