$NetBSD: patch-lib_bch.c,v 1.2 2017/09/18 23:07:49 jmcneill Exp $

--- lib/bch.c.orig	2017-07-10 17:07:38.000000000 +0000
+++ lib/bch.c
@@ -61,8 +61,10 @@
 #include <linux/bitops.h>
 #else
 #include <errno.h>
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/endian.h>
+#elif defined(__APPLE__)
+#include <machine/endian.h>
 #else
 #include <endian.h>
 #endif
@@ -71,7 +73,11 @@
 #include <string.h>
 
 #undef cpu_to_be32
+#if defined(__APPLE__)
+#define cpu_to_be32 htonl
+#else
 #define cpu_to_be32 htobe32
+#endif
 #define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))
 #define kmalloc(size, flags)	malloc(size)
 #define kzalloc(size, flags)	calloc(1, size)
@@ -117,7 +123,7 @@ struct gf_poly_deg1 {
 };
 
 #ifdef USE_HOSTCC
-#ifndef __BSD_VISIBLE
+#if !defined(__BSD_VISIBLE) && !defined(__APPLE__)
 static int fls(int x)
 {
 	int r = 32;
