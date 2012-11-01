$NetBSD: patch-src_sub.c,v 1.1 2012/11/01 19:42:01 joerg Exp $

--- src/sub.c.orig	2012-10-30 20:00:12.000000000 +0000
+++ src/sub.c
@@ -89,7 +89,7 @@ void prng_sub_reset(struct prng *gen)
  *      gen:  Pointer to a struct prng.
  *
  */
-inline double prng_sub_get_next(struct prng *gen)
+double prng_sub_get_next(struct prng *gen)
 {
   prng_num j;
   double tmp;
@@ -127,7 +127,7 @@ void prng_sub_get_array(struct prng *gen
  *      gen:  Pointer to a struct prng.
  *
  */
-inline prng_num prng_sub_get_next_int(struct prng *gen)
+prng_num prng_sub_get_next_int(struct prng *gen)
 {
   prng_num j,tmp;
 
