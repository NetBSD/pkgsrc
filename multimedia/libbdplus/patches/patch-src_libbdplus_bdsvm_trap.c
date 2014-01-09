$NetBSD: patch-src_libbdplus_bdsvm_trap.c,v 1.2 2014/01/09 10:25:14 wiz Exp $

Fix build on systems without fseeko.

--- src/libbdplus/bdsvm/trap.c.orig	2013-12-18 12:13:09.000000000 +0000
+++ src/libbdplus/bdsvm/trap.c
@@ -54,6 +54,10 @@
 #  define fseeko fseeko64
 #endif
 
+#ifndef fseeko
+#define fseeko fseek
+#endif
+
 /* Set this in CFLAGS to debug gcrypt MPIs and S-expressions */
 #ifndef GCRYPT_DEBUG
 #define GCRYPT_DEBUG 0
