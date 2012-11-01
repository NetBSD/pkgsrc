$NetBSD: patch-src_external.c,v 1.1 2012/11/01 19:42:01 joerg Exp $

--- src/external.c.orig	2012-10-30 20:00:20.000000000 +0000
+++ src/external.c
@@ -139,7 +139,7 @@ static unsigned int tt800_mag01[2]=
  *      gen:  Pointer to a struct prng.
  *
  */
-inline prng_num prng_tt800_get_next_int(struct prng *gen)
+prng_num prng_tt800_get_next_int(struct prng *gen)
 {
 unsigned int y;
 struct tt800_state *g;
@@ -189,7 +189,7 @@ return(y);
  *      gen:  Pointer to a struct prng.
  *
  */
-inline double prng_tt800_get_next(struct prng *gen)
+double prng_tt800_get_next(struct prng *gen)
 {
 return(prng_tt800_get_next_int(gen) * TT800_INV_MOD);
 }
@@ -223,7 +223,7 @@ struct ctg_state
  *      gen:  Pointer to a struct prng.
  *
  */
-inline prng_num prng_ctg_get_next_int(struct prng *gen)
+prng_num prng_ctg_get_next_int(struct prng *gen)
 {
 unsigned int b;
 struct ctg_state *g;
@@ -247,7 +247,7 @@ return(g->s1 ^ g->s2 ^ g->s3);
  *      gen:  Pointer to a struct prng.
  *
  */
-inline double prng_ctg_get_next(struct prng *gen)
+double prng_ctg_get_next(struct prng *gen)
 {
 return(prng_ctg_get_next_int(gen) * 2.3283064365e-10);
 }
@@ -285,7 +285,7 @@ struct mrg_state
  *      gen:  Pointer to a struct prng.
  *
  */
-inline prng_num prng_mrg_get_next_int(struct prng *gen)
+prng_num prng_mrg_get_next_int(struct prng *gen)
 {
 int h,p1,p5;
 struct mrg_state *g;
@@ -312,7 +312,7 @@ return(g->x1);
  *      gen:  Pointer to a struct prng.
  *
  */
-inline double prng_mrg_get_next(struct prng *gen)
+double prng_mrg_get_next(struct prng *gen)
 {
 return(prng_mrg_get_next_int(gen) * 4.656612873077393e-10);
 }
@@ -350,7 +350,7 @@ struct cmrg_state
  *      gen:  Pointer to a struct prng.
  *
  */
-inline prng_num prng_cmrg_get_next_int(struct prng *gen)
+prng_num prng_cmrg_get_next_int(struct prng *gen)
 {
 int h, p12, p13, p21, p23;
 struct cmrg_state *g;
@@ -385,7 +385,7 @@ else
  *      gen:  Pointer to a struct prng.
  *
  */
-inline double prng_cmrg_get_next(struct prng *gen)
+double prng_cmrg_get_next(struct prng *gen)
 {
 return(prng_cmrg_get_next_int(gen) * 4.656612873077393e-10);
 }
