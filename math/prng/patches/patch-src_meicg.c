$NetBSD: patch-src_meicg.c,v 1.1 2012/11/01 19:42:01 joerg Exp $

--- src/meicg.c.orig	2012-10-30 20:00:30.000000000 +0000
+++ src/meicg.c
@@ -106,7 +106,7 @@ void prng_meicg_seed(struct prng *gen,pr
  *      gen:  Pointer to a struct prng.
  *
  */
-inline prng_num prng_meicg_get_next_int(struct prng *gen)
+prng_num prng_meicg_get_next_int(struct prng *gen)
 {
   s_prng_num an, sum, inv, n;
 
@@ -144,7 +144,7 @@ inline prng_num prng_meicg_get_next_int(
  *      gen:  Pointer to a struct prng.
  *
  */
-inline double prng_meicg_get_next(struct prng *gen)
+double prng_meicg_get_next(struct prng *gen)
 {
   return(prng_meicg_get_next_int(gen) * gen->data.meicg_data.inv_p);
 }
