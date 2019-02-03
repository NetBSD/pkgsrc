$NetBSD: patch-src_rtl__adsb.c,v 1.3 2019/02/03 10:42:19 tnn Exp $

GCC does not like duplicate static keyword

--- src/rtl_adsb.c.orig	2019-02-03 09:38:28.472977070 +0000
+++ src/rtl_adsb.c
@@ -183,7 +183,7 @@ int magnitute(uint8_t *buf, int len)
 	return len/2;
 }
 
-static static inline uint16_t single_manchester(uint16_t a, uint16_t b, uint16_t c, uint16_t d)
+static inline uint16_t single_manchester(uint16_t a, uint16_t b, uint16_t c, uint16_t d)
 /* takes 4 consecutive real samples, return 0 or 1, BADSAMPLE on error */
 {
 	int bit, bit_p;
@@ -224,17 +224,17 @@ static static inline uint16_t single_man
 	return BADSAMPLE;
 }
 
-static static inline uint16_t min16(uint16_t a, uint16_t b)
+static inline uint16_t min16(uint16_t a, uint16_t b)
 {
 	return a<b ? a : b;
 }
 
-static static inline uint16_t max16(uint16_t a, uint16_t b)
+static inline uint16_t max16(uint16_t a, uint16_t b)
 {
 	return a>b ? a : b;
 }
 
-static static inline int preamble(uint16_t *buf, int i)
+static inline int preamble(uint16_t *buf, int i)
 /* returns 0/1 for preamble at index i */
 {
 	int i2;
