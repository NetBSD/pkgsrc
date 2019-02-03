$NetBSD: patch-src_rtl__power.c,v 1.3 2019/02/03 10:42:19 tnn Exp $

GCC does not like duplicate static keyword

--- src/rtl_power.c.orig	2019-02-03 09:38:28.488240147 +0000
+++ src/rtl_power.c
@@ -250,7 +250,7 @@ void sine_table(int size)
 	}
 }
 
-static static inline int16_t FIX_MPY(int16_t a, int16_t b)
+static inline int16_t FIX_MPY(int16_t a, int16_t b)
 /* fixed point multiply and scale */
 {
 	int c = ((int)a * (int)b) >> 14;
