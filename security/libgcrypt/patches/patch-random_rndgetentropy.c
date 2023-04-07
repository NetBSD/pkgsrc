$NetBSD: patch-random_rndgetentropy.c,v 1.1 2023/04/07 09:15:55 adam Exp $

Use getrandom(2) conditionally. https://dev.gnupg.org/T6442

--- random/rndgetentropy.c.orig	2023-04-07 08:56:42.000000000 +0000
+++ random/rndgetentropy.c
@@ -81,6 +81,7 @@ _gcry_rndgetentropy_gather_random (void 
       do
         {
           _gcry_pre_syscall ();
+#ifdef HAVE_GETRANDOM
           if (fips_mode ())
             {
               /* DRBG chaining defined in SP 800-90A (rev 1) specify
@@ -98,6 +99,7 @@ _gcry_rndgetentropy_gather_random (void 
               ret = getrandom (buffer, nbytes, GRND_RANDOM);
             }
           else
+#endif
             {
               nbytes = length < sizeof (buffer) ? length : sizeof (buffer);
               ret = getentropy (buffer, nbytes);
