$NetBSD: patch-include__openssl__thread.h,v 1.1.1.1 2015/12/31 02:57:35 agc Exp $

NetBSD portability patches

--- include/openssl/thread.h.orig	2015-12-30 15:55:52.000000000 -0800
+++ include/openssl/thread.h	2015-12-30 18:06:05.000000000 -0800
@@ -87,6 +87,9 @@
 typedef union crypto_mutex_st {
   double alignment;
   uint8_t padding[3*sizeof(int) + 5*sizeof(unsigned) + 16 + 8];
+#if defined(__NetBSD__)
+  uint8_t	nbpad[64 + 8];
+#endif
 } CRYPTO_MUTEX;
 #endif
 
