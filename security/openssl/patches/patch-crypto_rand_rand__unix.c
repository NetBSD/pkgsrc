$NetBSD: patch-crypto_rand_rand__unix.c,v 1.3 2021/08/25 15:22:05 adam Exp $

Fix building on older Darwin.

--- crypto/rand/rand_unix.c.orig	2021-08-25 15:07:06.000000000 +0000
+++ crypto/rand/rand_unix.c
@@ -35,6 +35,7 @@
 # include <sys/param.h>
 #endif
 #if defined(__APPLE__)
+# include <CommonCrypto/CommonCryptoError.h>
 # include <CommonCrypto/CommonRandom.h>
 #endif
 
