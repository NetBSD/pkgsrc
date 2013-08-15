$NetBSD: patch-src_decoder.hpp,v 1.1 2013/08/15 16:29:25 joerg Exp $

--- src/decoder.hpp.orig	2013-08-15 15:47:23.000000000 +0000
+++ src/decoder.hpp
@@ -35,7 +35,7 @@
 namespace zmq
 {
 
-    class i_msg_sink;
+    struct i_msg_sink;
 
     //  Helper base class for decoders that know the amount of data to read
     //  in advance at any moment. Knowing the amount in advance is a property
