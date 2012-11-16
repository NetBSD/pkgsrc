$NetBSD: patch-spunk_textstrm.cc,v 1.1 2012/11/16 00:37:47 joerg Exp $

--- spunk/textstrm.cc.orig	1996-11-07 18:06:52.000000000 +0000
+++ spunk/textstrm.cc
@@ -66,8 +66,8 @@ void TextFileStream::MakeLineIndex (int 
 // LineLen is the estimated length of a line in the file used for
 // estimating the size of the buffer.
 {
-    static const Delta   = 100;
-    static const BufSize = 4096;
+    static const u32 Delta   = 100;
+    static const u32 BufSize = 4096;
 
     // Estimate the count of lines
     if ((Limit = Size / LineLen) < 100) {
