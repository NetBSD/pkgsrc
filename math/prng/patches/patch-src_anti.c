$NetBSD: patch-src_anti.c,v 1.1 2012/11/01 19:42:01 joerg Exp $

--- src/anti.c.orig	2012-10-30 20:00:10.000000000 +0000
+++ src/anti.c
@@ -82,7 +82,7 @@ void prng_anti_reset(struct prng *gen)
  *      gen:  Pointer to a struct prng.
  *
  */
-inline double prng_anti_get_next(struct prng *gen)
+double prng_anti_get_next(struct prng *gen)
 {
   return (1. - prng_get_next(gen->data.anti_data.prng));
 }
@@ -114,7 +114,7 @@ void prng_anti_get_array(struct prng *ge
  *
  */
 /*
-inline prng_num prng_anti_get_next_int(struct prng *gen)
+prng_num prng_anti_get_next_int(struct prng *gen)
 ... undefined !!!
 */
 
