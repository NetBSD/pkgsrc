$NetBSD: patch-src_mkbitmap.c,v 1.1 2018/01/31 10:22:48 jperkin Exp $

Set _XOPEN_SOURCE correctly.

--- src/mkbitmap.c.orig	2017-02-19 04:39:08.000000000 +0000
+++ src/mkbitmap.c
@@ -7,7 +7,9 @@
    filter (evening out background gradients), lowpass filter
    (smoothing foreground details), interpolated scaling, inversion. */
 
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _XOPEN_SOURCE 500
+#endif
 
 #ifdef HAVE_CONFIG_H
 #include <config.h>
