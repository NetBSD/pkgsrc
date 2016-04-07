$NetBSD: patch-src_rtl__adsb.c,v 1.1 2016/04/07 12:10:55 wiedi Exp $

Use "static inline" to fix build on osx

--- src/rtl_adsb.c.orig	2014-02-07 01:04:24.000000000 +0000
+++ src/rtl_adsb.c
@@ -180,7 +180,7 @@ int magnitute(uint8_t *buf, int len)
 	return len/2;
 }
 
-inline uint16_t single_manchester(uint16_t a, uint16_t b, uint16_t c, uint16_t d)
+static inline uint16_t single_manchester(uint16_t a, uint16_t b, uint16_t c, uint16_t d)
 /* takes 4 consecutive real samples, return 0 or 1, BADSAMPLE on error */
 {
 	int bit, bit_p;
@@ -221,17 +221,17 @@ inline uint16_t single_manchester(uint16
 	return BADSAMPLE;
 }
 
-inline uint16_t min16(uint16_t a, uint16_t b)
+static inline uint16_t min16(uint16_t a, uint16_t b)
 {
 	return a<b ? a : b;
 }
 
-inline uint16_t max16(uint16_t a, uint16_t b)
+static inline uint16_t max16(uint16_t a, uint16_t b)
 {
 	return a>b ? a : b;
 }
 
-inline int preamble(uint16_t *buf, int i)
+static inline int preamble(uint16_t *buf, int i)
 /* returns 0/1 for preamble at index i */
 {
 	int i2;
