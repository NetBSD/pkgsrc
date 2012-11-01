$NetBSD: patch-src_mt19937.c,v 1.1 2012/11/01 19:42:01 joerg Exp $

--- src/mt19937.c.orig	2012-10-30 20:00:22.000000000 +0000
+++ src/mt19937.c
@@ -137,7 +137,7 @@
  *	seed: used for initializing array
  *
  */
-inline void prng_mt19937_seed( struct prng *gen, prng_num seed )
+void prng_mt19937_seed( struct prng *gen, prng_num seed )
 {
   int i;
 
@@ -172,7 +172,7 @@ void prng_mt19937_reset(struct prng *gen
  *      gen:  Pointer to a struct prng.
  *
  */
-inline prng_num prng_mt19937_get_next_int(struct prng *gen)
+prng_num prng_mt19937_get_next_int(struct prng *gen)
 {
 #define MT  gen->data.mt19937_data.mt
 #define MTI gen->data.mt19937_data.mti
@@ -220,7 +220,7 @@ inline prng_num prng_mt19937_get_next_in
  *      gen:  Pointer to a struct prng.
  *
  */
-inline double prng_mt19937_get_next(struct prng *gen)
+double prng_mt19937_get_next(struct prng *gen)
 {
   /* reals: [0,1)-interval   */
   /* multiply with 1. / 2^32 */
