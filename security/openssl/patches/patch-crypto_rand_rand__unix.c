$NetBSD: patch-crypto_rand_rand__unix.c,v 1.4 2022/01/11 13:54:01 schmonz Exp $

Apply upstream c023d98dcf2ba1cc30f545ae54d0e037e80a8794:
Darwin platform allows to build on releases before Yosemite/ios 8.

--- crypto/rand/rand_unix.c.orig	2021-08-24 13:38:47.000000000 +0000
+++ crypto/rand/rand_unix.c
@@ -34,9 +34,6 @@
 #if defined(__OpenBSD__)
 # include <sys/param.h>
 #endif
-#if defined(__APPLE__)
-# include <CommonCrypto/CommonRandom.h>
-#endif
 
 #if defined(OPENSSL_SYS_UNIX) || defined(__DJGPP__)
 # include <sys/types.h>
@@ -381,7 +378,7 @@ static ssize_t syscall_random(void *buf,
         if (errno != ENOSYS)
             return -1;
     }
-#  elif defined(__APPLE__)
+#  elif defined(OPENSSL_APPLE_CRYPTO_RANDOM)
     if (CCRandomGenerateBytes(buf, buflen) == kCCSuccess)
 	    return (ssize_t)buflen;
 
