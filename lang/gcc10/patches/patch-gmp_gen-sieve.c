$NetBSD: patch-gmp_gen-sieve.c,v 1.1 2024/04/01 14:33:57 js Exp $

Fix compiling with GCC 4.4.2 on QNX.

--- gmp/gen-sieve.c.orig	2023-07-29 13:42:16.000000000 +0000
+++ gmp/gen-sieve.c
@@ -95,8 +95,9 @@ generate (int limb_bits, int limit)
 void
 setmask (mpz_t mask, int a, int b)
 {
+  unsigned i;
   mpz_set_ui (mask, 0);
-  for (unsigned i = 0; i < 2 * a * b; ++i)
+  for (i = 0; i < 2 * a * b; ++i)
     if ((bit_to_n (i) % a == 0) || (bit_to_n (i) % b == 0))
       mpz_setbit (mask, i);
 }
