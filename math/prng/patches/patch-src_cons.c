$NetBSD: patch-src_cons.c,v 1.1 2012/11/01 19:42:01 joerg Exp $

--- src/cons.c.orig	2012-10-30 20:00:14.000000000 +0000
+++ src/cons.c
@@ -89,7 +89,7 @@ void prng_con_reset(struct prng *gen)
  *      gen:  Pointer to a struct prng.
  *
  */
-inline double prng_con_get_next(struct prng *gen)
+double prng_con_get_next(struct prng *gen)
 {
   return(prng_get_next(gen->data.con_data.prng));
 }
@@ -119,7 +119,7 @@ void prng_con_get_array(struct prng *gen
  *      gen:  Pointer to a struct prng.
  *
  */
-inline prng_num prng_con_get_next_int(struct prng *gen)
+prng_num prng_con_get_next_int(struct prng *gen)
 {
   return(prng_get_next_int(gen->data.con_data.prng));
 }
