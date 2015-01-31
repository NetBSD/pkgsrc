$NetBSD: patch-src_libbdplus_bdsvm_segment.c,v 1.3 2015/01/31 21:48:03 adam Exp $

Fix build on systems without fseeko().

--- src/libbdplus/bdsvm/segment.c.orig	2013-12-18 12:13:09.000000000 +0000
+++ src/libbdplus/bdsvm/segment.c
@@ -39,6 +39,10 @@
 #  define fseeko fseeko64
 #endif
 
+#ifndef fseeko
+#define fseeko fseek
+#endif
+
 /*
  *
  */
