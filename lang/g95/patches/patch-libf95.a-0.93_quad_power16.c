$NetBSD: patch-libf95.a-0.93_quad_power16.c,v 1.1 2013/03/02 18:05:46 joerg Exp $

--- libf95.a-0.93/quad/power16.c.orig	2013-03-01 11:16:07.000000000 +0000
+++ libf95.a-0.93/quad/power16.c
@@ -36,10 +36,11 @@
 
 #define power_r16_i4 prefix(power_r16_i4)
 
+void unpack_quad(void *v, unsigned *mantissa, int *exp, int *sign);
 
 /* int_power16()-- Core of integer powers. */
 
-static int_power16(unpacked16 *base, long long e0, unpacked16 *result) {
+static void int_power16(unpacked16 *base, long long e0, unpacked16 *result) {
 int negative, negative_exp;
 unsigned long long exp;
 unpacked16 one;
