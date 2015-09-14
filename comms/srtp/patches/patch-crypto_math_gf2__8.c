$NetBSD: patch-crypto_math_gf2__8.c,v 1.1 2015/09/14 13:30:03 joerg Exp $

--- crypto/math/gf2_8.c.orig	2015-09-13 19:22:59.000000000 +0000
+++ crypto/math/gf2_8.c
@@ -50,7 +50,7 @@
 
 /* gf2_8_shift() moved to gf2_8.h as an inline function */
 
-inline gf2_8
+static inline gf2_8
 gf2_8_multiply(gf2_8 x, gf2_8 y) {
   gf2_8 z = 0;
 
