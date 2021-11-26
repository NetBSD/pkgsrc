$NetBSD: patch-mpz_inp__raw.c,v 1.1 2021/11/26 12:23:08 wiz Exp $

Fix for CVE-2021-43618
https://gmplib.org/repo/gmp-6.2/rev/561a9c25298e

--- mpz/inp_raw.c.orig	2020-11-14 18:45:09.000000000 +0000
+++ mpz/inp_raw.c
@@ -88,8 +88,11 @@ mpz_inp_raw (mpz_ptr x, FILE *fp)
 
   abs_csize = ABS (csize);
 
+  if (UNLIKELY (abs_csize > ~(mp_bitcnt_t) 0 / 8))
+    return 0; /* Bit size overflows */
+
   /* round up to a multiple of limbs */
-  abs_xsize = BITS_TO_LIMBS (abs_csize*8);
+  abs_xsize = BITS_TO_LIMBS ((mp_bitcnt_t) abs_csize * 8);
 
   if (abs_xsize != 0)
     {
