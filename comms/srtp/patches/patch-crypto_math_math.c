$NetBSD: patch-crypto_math_math.c,v 1.1 2015/09/14 13:30:03 joerg Exp $

--- crypto/math/math.c.orig	2015-09-13 19:23:02.000000000 +0000
+++ crypto/math/math.c
@@ -173,7 +173,7 @@ v32_weight(v32_t a) {
   return wt;
 }
 
-inline unsigned char
+static inline unsigned char
 v32_distance(v32_t x, v32_t y) {
   x.value ^= y.value;
   return v32_weight(x);
@@ -524,13 +524,13 @@ A_times_x_plus_b(uint8_t A[8], uint8_t x
   return b;
 }
 
-inline void
+static inline void
 v16_copy_octet_string(v16_t *x, const uint8_t s[2]) {
   x->v8[0]  = s[0];
   x->v8[1]  = s[1];
 }
 
-inline void
+static inline void
 v32_copy_octet_string(v32_t *x, const uint8_t s[4]) {
   x->v8[0]  = s[0];
   x->v8[1]  = s[1];
@@ -538,7 +538,7 @@ v32_copy_octet_string(v32_t *x, const ui
   x->v8[3]  = s[3];
 }
 
-inline void
+static inline void
 v64_copy_octet_string(v64_t *x, const uint8_t s[8]) {
   x->v8[0]  = s[0];
   x->v8[1]  = s[1];
@@ -632,7 +632,7 @@ v128_set_bit_to(v128_t *x, int i, int y)
 #endif /* DATATYPES_USE_MACROS */
 
 
-inline void
+static inline void
 v128_left_shift2(v128_t *x, int num_bits) {
   int i;
   int word_shift = num_bits >> 5;
