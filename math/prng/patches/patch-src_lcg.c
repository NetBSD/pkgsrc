$NetBSD: patch-src_lcg.c,v 1.1 2012/11/01 19:42:01 joerg Exp $

--- src/lcg.c.orig	2012-10-30 20:00:32.000000000 +0000
+++ src/lcg.c
@@ -111,7 +111,7 @@ void prng_lcg_seed(struct prng *gen,prng
  *      gen:  Pointer to a struct prng.
  *
  */
-inline prng_num prng_lcg_get_next_int(struct prng *gen)
+prng_num prng_lcg_get_next_int(struct prng *gen)
 {
   s_prng_num ax, current;
 
@@ -130,7 +130,7 @@ inline prng_num prng_lcg_get_next_int(st
  *      gen:  Pointer to a struct prng.
  *
  */
-inline double prng_lcg_get_next(struct prng *gen)
+double prng_lcg_get_next(struct prng *gen)
 {
   return(prng_lcg_get_next_int(gen) * gen->data.lcg_data.inv_p);
 }
