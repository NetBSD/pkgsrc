$NetBSD: patch-src_icg.c,v 1.1 2012/11/01 19:42:01 joerg Exp $

--- src/icg.c.orig	2012-10-30 20:00:34.000000000 +0000
+++ src/icg.c
@@ -110,7 +110,7 @@ void prng_icg_seed(struct prng *gen,prng
  *      gen:  Pointer to a struct prng.
  *
  */
-inline prng_num prng_icg_get_next_int(struct prng *gen)
+prng_num prng_icg_get_next_int(struct prng *gen)
 {
   s_prng_num inv, current, prod;
   
@@ -135,7 +135,7 @@ inline prng_num prng_icg_get_next_int(st
  *      gen:  Pointer to a struct prng.
  *
  */
-inline double prng_icg_get_next(struct prng *gen)
+double prng_icg_get_next(struct prng *gen)
 {
   return(prng_icg_get_next_int(gen) * gen->data.icg_data.inv_p);
 }
