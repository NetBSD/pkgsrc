$NetBSD: patch-src_libbdplus_bdsvm_segment.c,v 1.2 2014/01/09 10:25:14 wiz Exp $

Fix build on systems without fseeko.

--- src/libbdplus/bdsvm/segment.c.orig	2013-12-18 12:13:09.000000000 +0000
+++ src/libbdplus/bdsvm/segment.c
@@ -38,6 +38,10 @@
 #  define fseeko fseeko64
 #endif
 
+#ifndef fseeko
+#define fseeko fseek
+#endif
+
 /*
  *
  */
