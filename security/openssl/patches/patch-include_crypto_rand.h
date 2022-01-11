$NetBSD: patch-include_crypto_rand.h,v 1.1 2022/01/11 13:54:01 schmonz Exp $

Apply upstream c023d98dcf2ba1cc30f545ae54d0e037e80a8794:
Darwin platform allows to build on releases before Yosemite/ios 8.

--- include/crypto/rand.h.orig	2021-08-24 13:38:47.000000000 +0000
+++ include/crypto/rand.h
@@ -20,6 +20,16 @@
 
 # include <openssl/rand.h>
 
+# if defined(__APPLE__) && !defined(OPENSSL_NO_APPLE_CRYPTO_RANDOM)
+#  include <Availability.h>
+#  if (defined(__MAC_OS_X_VERSION_MIN_REQUIRED) && __MAC_OS_X_VERSION_MIN_REQUIRED >= 101000) || \
+     (defined(__IPHONE_OS_VERSION_MIN_REQUIRED) && __IPHONE_OS_VERSION_MIN_REQUIRED >= 80000)
+#   define OPENSSL_APPLE_CRYPTO_RANDOM 1
+#   include <CommonCrypto/CommonCryptoError.h>
+#   include <CommonCrypto/CommonRandom.h>
+#  endif
+# endif
+
 /* forward declaration */
 typedef struct rand_pool_st RAND_POOL;
 
