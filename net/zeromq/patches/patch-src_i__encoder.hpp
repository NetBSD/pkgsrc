$NetBSD: patch-src_i__encoder.hpp,v 1.1 2013/08/15 16:29:25 joerg Exp $

--- src/i_encoder.hpp.orig	2013-08-15 15:48:37.000000000 +0000
+++ src/i_encoder.hpp
@@ -27,7 +27,7 @@ namespace zmq
 {
 
     //  Forward declaration
-    class i_msg_source;
+    struct i_msg_source;
 
     //  Interface to be implemented by message encoder.
 
