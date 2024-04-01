$NetBSD: patch-gmp_mpz_nextprime.c,v 1.1 2024/04/01 14:33:57 js Exp $

Fix compiling with GCC 4.4.2 on QNX.

--- gmp/mpz/nextprime.c.orig	2023-07-29 13:42:17.000000000 +0000
+++ gmp/mpz/nextprime.c
@@ -113,7 +113,8 @@ findnext_small (unsigned t, short diff)
   for (; ; t += diff)
     {
       unsigned prime = 3;
-      for (int i = 0; ; prime += primegap_small[i++])
+      int i;
+      for (i = 0; ; prime += primegap_small[i++])
 	{
 	  unsigned q, r;
 	  q = t / prime;
@@ -182,14 +183,18 @@ findnext (mpz_ptr p,
       i = 0;
       last_prime = 3;
       /* THINK: should we get rid of sieve_limit and use (i < prime_limit)? */
-      for (mp_limb_t j = 4, *sp = sieve; j < sieve_limit; j += GMP_LIMB_BITS * 3)
-	for (mp_limb_t b = j, x = ~ *(sp++); x != 0; b += 3, x >>= 1)
-	  if (x & 1)
-	    {
-	      mp_limb_t prime = b | 1;
-	      primegap_tmp[i++] = prime - last_prime;
-	      last_prime = prime;
-	    }
+      mp_limb_t j, *sp;
+      for (j = 4, sp = sieve; j < sieve_limit; j += GMP_LIMB_BITS * 3)
+        {
+          mp_limb_t b, x;
+	  for (b = j, x = ~ *(sp++); x != 0; b += 3, x >>= 1)
+	    if (x & 1)
+	      {
+	        mp_limb_t prime = b | 1;
+	        primegap_tmp[i++] = prime - last_prime;
+	        last_prime = prime;
+	      }
+        }
 
       /* Both primesieve and prime_limit ignore the first two primes. */
       ASSERT(i == prime_limit);
