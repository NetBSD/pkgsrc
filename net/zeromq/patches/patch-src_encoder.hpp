$NetBSD: patch-src_encoder.hpp,v 1.1 2013/08/15 16:29:25 joerg Exp $

--- src/encoder.hpp.orig	2013-08-15 15:48:20.000000000 +0000
+++ src/encoder.hpp
@@ -40,7 +40,7 @@
 namespace zmq
 {
 
-    class i_msg_source;
+    struct i_msg_source;
 
     //  Helper base class for encoders. It implements the state machine that
     //  fills the outgoing buffer. Derived classes should implement individual
