$NetBSD: patch-gmp_mpz_primorial_ui.c,v 1.1 2024/04/01 14:33:57 js Exp $

Fix compiling with GCC 4.4.2 on QNX.

--- gmp/mpz/primorial_ui.c.orig	2023-07-29 13:42:17.000000000 +0000
+++ gmp/mpz/primorial_ui.c
@@ -106,13 +106,17 @@ mpz_primorial_ui (mpz_ptr res, unsigned 
 	max_prod = GMP_NUMB_MAX / n;
 
 	/* Loop on sieved primes. */
-	for (mp_limb_t i = 4, *sp = sieve; i < n; i += GMP_LIMB_BITS * 3)
-	  for (mp_limb_t b = i, x = ~ *(sp++); x != 0; b += 3, x >>= 1)
-	    if (x & 1)
-	      {
-		mp_limb_t prime = b | 1;
-		FACTOR_LIST_STORE (prime, prod, max_prod, factors, j);
-	      }
+        mp_limb_t i, *sp;
+	for (i = 4, sp = sieve; i < n; i += GMP_LIMB_BITS * 3)
+          {
+            mp_limb_t b, x;
+	    for (b = i, x = ~ *(sp++); x != 0; b += 3, x >>= 1)
+	      if (x & 1)
+	        {
+		  mp_limb_t prime = b | 1;
+		  FACTOR_LIST_STORE (prime, prod, max_prod, factors, j);
+	        }
+          }
       }
 
       if (j != 0)
