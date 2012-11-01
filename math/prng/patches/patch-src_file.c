$NetBSD: patch-src_file.c,v 1.1 2012/11/01 19:42:01 joerg Exp $

--- src/file.c.orig	2012-10-30 20:00:18.000000000 +0000
+++ src/file.c
@@ -88,7 +88,7 @@ void prng_file_reset(struct prng *gen)
  *      gen:  Pointer to a struct prng.
  *
  */
-inline double prng_afile_get_next(struct prng *gen)
+double prng_afile_get_next(struct prng *gen)
 {
   double d;
   char line[64];
@@ -135,7 +135,7 @@ void prng_afile_get_array(struct prng *g
  *      gen:  Pointer to a struct prng.
  *
  */
-inline double prng_bfile_get_next(struct prng *gen)
+double prng_bfile_get_next(struct prng *gen)
 {
   prng_num n;
 
