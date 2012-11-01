$NetBSD: patch-src_dicg.c,v 1.1 2012/11/01 19:42:01 joerg Exp $

--- src/dicg.c.orig	2012-10-30 20:00:40.000000000 +0000
+++ src/dicg.c
@@ -441,7 +441,7 @@ t->pton[29] = 1073741823;
  * Algorithm by Karin Schaber and Otmar Lendl.
  *
  */                                                  
-inline prng_num prng_dicg_multiply(int k,prng_num c, prng_num d)
+prng_num prng_dicg_multiply(int k,prng_num c, prng_num d)
 {
   int i;
   struct mtable *t;
@@ -593,7 +593,7 @@ void prng_dicg_seed(struct prng *gen,prn
  *      gen:  Pointer to a struct prng.
  *
  */
-inline prng_num prng_dicg_get_next_int(struct prng *gen) /* DUMMY !!!!*/
+prng_num prng_dicg_get_next_int(struct prng *gen) /* DUMMY !!!!*/
 {
   s_prng_num inv, current, prod;
 
@@ -619,7 +619,7 @@ inline prng_num prng_dicg_get_next_int(s
  *      gen:  Pointer to a struct prng.
  *
  */
-inline double prng_dicg_get_next(struct prng *gen)
+double prng_dicg_get_next(struct prng *gen)
 {
   return(prng_dicg_get_next_int(gen) * gen->data.dicg_data.inv_p);
 }
