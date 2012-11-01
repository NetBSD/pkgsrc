$NetBSD: patch-src_compound.c,v 1.1 2012/11/01 19:42:01 joerg Exp $

--- src/compound.c.orig	2012-10-30 20:00:16.000000000 +0000
+++ src/compound.c
@@ -105,7 +105,7 @@ void prng_compound_seed(struct prng *gen
  *      gen:  Pointer to a struct prng.
  *
  */
-inline double prng_compound_get_next(struct prng *gen)
+double prng_compound_get_next(struct prng *gen)
 {
   int i;
   double sum = 0.0;
