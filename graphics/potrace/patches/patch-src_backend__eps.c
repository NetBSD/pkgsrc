$NetBSD: patch-src_backend__eps.c,v 1.1 2018/01/31 10:22:48 jperkin Exp $

Set _XOPEN_SOURCE correctly.

--- src/backend_eps.c.orig	2017-02-19 04:39:08.000000000 +0000
+++ src/backend_eps.c
@@ -8,7 +8,9 @@
    output. Postscript compression is optionally supplied via the
    functions in flate.c. */
 
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _XOPEN_SOURCE 500
+#endif
 
 #ifdef HAVE_CONFIG_H
 #include <config.h>
