$NetBSD: patch-c-blosc_blosc_blosc.c,v 1.1 2016/08/16 02:42:48 maya Exp $

Workaround NetBSD-7.99.35 missing C11 includes and having C11 support
PR standards/51416

--- c-blosc/blosc/blosc.c.orig	2016-07-03 11:46:48.000000000 +0000
+++ c-blosc/blosc/blosc.c
@@ -59,7 +59,7 @@
 #endif
 
 /* If C11 is supported, use it's built-in aligned allocation. */
-#if __STDC_VERSION__ >= 201112L
+#if 0
   #include <stdalign.h>
 #endif
 
