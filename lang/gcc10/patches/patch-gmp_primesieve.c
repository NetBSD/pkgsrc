$NetBSD: patch-gmp_primesieve.c,v 1.1 2024/04/01 14:33:57 js Exp $

Fix compiling with GCC 4.4.2 on QNX.

--- gmp/primesieve.c.orig	2023-07-29 13:42:17.000000000 +0000
+++ gmp/primesieve.c
@@ -288,8 +288,8 @@ gmp_primesieve (mp_ptr bit_array, mp_lim
   bits = n_fto_bit(n);
   size = bits / GMP_LIMB_BITS + 1;
 
-  for (mp_size_t j = 0, lim = MIN (size, PRIMESIEVE_NUMBEROF_TABLE);
-       j < lim; ++j)
+  mp_size_t j, lim;
+  for (j = 0, lim = MIN (size, PRIMESIEVE_NUMBEROF_TABLE); j < lim; ++j)
     bit_array [j] = presieved [j]; /* memcopy? */
 
   if (size > PRIMESIEVE_NUMBEROF_TABLE) {
