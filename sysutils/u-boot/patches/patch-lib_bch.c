$NetBSD: patch-lib_bch.c,v 1.4 2019/10/06 17:02:10 bad Exp $

--- lib/bch.c.orig	2018-11-14 16:10:06.000000000 +0000
+++ lib/bch.c
@@ -60,8 +60,11 @@
 #include <linux/bitops.h>
 #else
 #include <errno.h>
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/endian.h>
+#elif defined(__APPLE__)
+#include <machine/endian.h>
+#include <libkern/OSByteOrder.h>
 #else
 #include <endian.h>
 #endif
@@ -70,7 +73,11 @@
 #include <string.h>
 
 #undef cpu_to_be32
+#if defined(__APPLE__)
+#define cpu_to_be32 OSSwapHostToBigInt32
+#else
 #define cpu_to_be32 htobe32
+#endif
 #define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))
 #define kmalloc(size, flags)	malloc(size)
 #define kzalloc(size, flags)	calloc(1, size)
@@ -116,7 +123,7 @@ struct gf_poly_deg1 {
 };
 
 #ifdef USE_HOSTCC
-#if !defined(__DragonFly__) && !defined(__FreeBSD__)
+#if !defined(__DragonFly__) && !defined(__FreeBSD__) && !defined(__APPLE__)
 static int fls(int x)
 {
 	int r = 32;
