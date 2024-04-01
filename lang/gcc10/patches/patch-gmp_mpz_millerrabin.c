$NetBSD: patch-gmp_mpz_millerrabin.c,v 1.1 2024/04/01 14:33:57 js Exp $

Fix compiling with GCC 4.4.2 on QNX.

--- gmp/mpz/millerrabin.c.orig	2023-07-29 13:42:17.000000000 +0000
+++ gmp/mpz/millerrabin.c
@@ -206,7 +206,8 @@ millerrabin (mpz_srcptr n, mpz_ptr x, mp
   if (mpz_cmp_ui (y, 1L) == 0 || mod_eq_m1 (y, n))
     return 1;
 
-  for (mp_bitcnt_t i = 1; i < k; ++i)
+  mp_bitcnt_t i;
+  for (i = 1; i < k; ++i)
     {
       mpz_powm_ui (y, y, 2L, n);
       if (mod_eq_m1 (y, n))
