$NetBSD: patch-spunk_stream.cc,v 1.1 2012/11/16 00:37:47 joerg Exp $

--- spunk/stream.cc.orig	1996-12-18 13:09:02.000000000 +0000
+++ spunk/stream.cc
@@ -347,7 +347,7 @@ void Stream::Write (const void*, size_t)
 
 void Stream::CopyFrom (Stream& S, size_t Count)
 {
-    static const BufSize = 4096;            // Size of copy buffer
+    static const size_t BufSize = 4096;            // Size of copy buffer
 
 
     // Check parameter
