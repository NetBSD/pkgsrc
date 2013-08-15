$NetBSD: patch-src_i__decoder.hpp,v 1.1 2013/08/15 16:29:25 joerg Exp $

--- src/i_decoder.hpp.orig	2013-08-15 15:47:52.000000000 +0000
+++ src/i_decoder.hpp
@@ -26,7 +26,7 @@
 namespace zmq
 {
 
-    class i_msg_sink;
+    struct i_msg_sink;
 
     //  Interface to be implemented by message decoder.
 
