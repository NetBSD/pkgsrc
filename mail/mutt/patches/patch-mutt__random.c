$NetBSD: patch-mutt__random.c,v 1.1 2020/11/11 18:57:15 otis Exp $

Cast to more portable C99 uint32_t

--- mutt_random.c.orig	2020-11-03 17:50:37.000000000 +0000
+++ mutt_random.c
@@ -29,7 +29,7 @@
 #include <sys/types.h>
 #include <unistd.h>
 
-static u_int32_t z[4]; /* Keep state for LFRS113 PRNG */
+static uint32_t z[4]; /* Keep state for LFRS113 PRNG */
 static int rand_bytes_produced = 0;
 static time_t time_last_reseed = 0;
 
@@ -92,11 +92,11 @@ void mutt_reseed (void)
    * Use as many of the lower order bits from the current time of day as the seed.
    * If the upper bound is truncated, that is fine.
    *
-   * tv_sec is integral of type integer or float.  Cast to 'u_int32_t' before
+   * tv_sec is integral of type integer or float.  Cast to 'uint32_t' before
    * bitshift in case it is a float. */
 
   /* Finally, set our seeds */
-  z[0] ^= (((u_int32_t) tv.tv_sec << 20) | tv.tv_usec);
+  z[0] ^= (((uint32_t) tv.tv_sec << 20) | tv.tv_usec);
   z[1] ^= getpid ()                             ^ z[0];
   z[2] ^= getppid ()                            ^ z[0];
   z[3] ^= (intptr_t) &z[3] ^ time_last_reseed   ^ z[0];
