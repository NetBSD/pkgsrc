$NetBSD: patch-src_avprofile.c,v 1.1 2012/06/25 11:49:10 joerg Exp $

--- src/avprofile.c.orig	2009-06-16 10:49:48.000000000 +0000
+++ src/avprofile.c
@@ -30,7 +30,7 @@ char offset0[4] = {0x00, 0x00, 0x00, 0x0
  * portability, payload types must be defined with their fields in the right
  * order.
  */
-#if defined(_ISOC99_SOURCE)
+#if defined(_ISOC99_SOURCE) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)
 // ISO C99's tagged syntax
 #define TYPE(val)		.type=(val)
 #define CLOCK_RATE(val)		.clock_rate=(val)
