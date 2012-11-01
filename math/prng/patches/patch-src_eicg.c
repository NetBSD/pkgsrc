$NetBSD: patch-src_eicg.c,v 1.1 2012/11/01 19:42:01 joerg Exp $

--- src/eicg.c.orig	2012-10-30 20:00:38.000000000 +0000
+++ src/eicg.c
@@ -120,7 +120,7 @@ void prng_eicg_seed(struct prng *gen,prn
  *      gen:  Pointer to a struct prng.
  *
  */
-inline prng_num prng_eicg_get_next_int(struct prng *gen)
+prng_num prng_eicg_get_next_int(struct prng *gen)
 {
   prng_num old;
 
@@ -138,7 +138,7 @@ inline prng_num prng_eicg_get_next_int(s
  *      gen:  Pointer to a struct prng.
  *
  */
-inline double prng_eicg_get_next(struct prng *gen)
+double prng_eicg_get_next(struct prng *gen)
 {
   return(prng_eicg_get_next_int(gen) * gen->data.eicg_data.inv_p);
 }
