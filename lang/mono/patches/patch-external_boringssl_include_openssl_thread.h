$NetBSD: patch-external_boringssl_include_openssl_thread.h,v 1.1 2022/02/08 13:39:17 gavan Exp $

--- external/boringssl/include/openssl/thread.h.orig	2021-02-22 15:51:10.000000000 +0000
+++ external/boringssl/include/openssl/thread.h
@@ -88,6 +88,9 @@ typedef pthread_rwlock_t CRYPTO_MUTEX;
 typedef union crypto_mutex_st {
   double alignment;
   uint8_t padding[3*sizeof(int) + 5*sizeof(unsigned) + 16 + 8];
+#if defined(__NetBSD__)
+  uint8_t nbpad[64 + 8];
+#endif
 } CRYPTO_MUTEX;
 #endif
 
