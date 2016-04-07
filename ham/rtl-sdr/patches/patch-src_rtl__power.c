$NetBSD: patch-src_rtl__power.c,v 1.1 2016/04/07 12:10:55 wiedi Exp $

Use "static inline" to fix build on osx

--- src/rtl_power.c.orig	2014-02-07 01:04:24.000000000 +0000
+++ src/rtl_power.c
@@ -249,7 +249,7 @@ void sine_table(int size)
 	}
 }
 
-inline int16_t FIX_MPY(int16_t a, int16_t b)
+static inline int16_t FIX_MPY(int16_t a, int16_t b)
 /* fixed point multiply and scale */
 {
 	int c = ((int)a * (int)b) >> 14;
