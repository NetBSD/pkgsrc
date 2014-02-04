$NetBSD: patch-src_lib_FB2Token.cpp,v 1.1 2014/02/04 00:13:03 joerg Exp $

clang warns about obsolete register keyword, so just remove it in the gperf
output.

--- src/lib/FB2Token.cpp.orig	2014-02-03 21:39:26.000000000 +0000
+++ src/lib/FB2Token.cpp
@@ -25,7 +25,9 @@ namespace libebook
 namespace
 {
 
+#define register
 #include "FB2Token.inc"
+#undef register
 
 }
 }
