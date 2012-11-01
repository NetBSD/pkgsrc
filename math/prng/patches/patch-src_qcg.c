$NetBSD: patch-src_qcg.c,v 1.1 2012/11/01 19:42:01 joerg Exp $

--- src/qcg.c.orig	2012-10-30 20:00:28.000000000 +0000
+++ src/qcg.c
@@ -107,7 +107,7 @@ void prng_qcg_seed(struct prng *gen,prng
  *      gen:  Pointer to a struct prng.
  *
  */
-inline prng_num prng_qcg_get_next_int(struct prng *gen)
+prng_num prng_qcg_get_next_int(struct prng *gen)
 {
   s_prng_num current, sum, square, q_term, l_term;
 
@@ -150,7 +150,7 @@ inline prng_num prng_qcg_get_next_int(st
  *      gen:  Pointer to a struct prng.
  *
  */
-inline double prng_qcg_get_next(struct prng *gen)
+double prng_qcg_get_next(struct prng *gen)
 {
   return(prng_qcg_get_next_int(gen) * gen->data.qcg_data.inv_p);
 }
