$NetBSD: patch-deps_openssl_openssl_crypto_init.c,v 1.1 2019/03/23 11:15:18 tsutsui Exp $

- pull fix from https://github.com/nodejs/node/pull/21848/commits/9868d403221bc9d566cb88a37510a182b7fbad3b
- apply similar ifdefs for NetBSD as FreeBSD and OpenBSD

--- deps/openssl/openssl/crypto/init.c.orig	2019-03-05 15:16:27.000000000 +0000
+++ deps/openssl/openssl/crypto/init.c
@@ -121,7 +121,8 @@ DEFINE_RUN_ONCE_STATIC(ossl_init_load_cr
 #ifdef OPENSSL_INIT_DEBUG
     fprintf(stderr, "OPENSSL_INIT: ossl_init_load_crypto_nodelete()\n");
 #endif
-#if !defined(OPENSSL_NO_DSO) && !defined(OPENSSL_USE_NODELETE)
+#if defined(OPENSSL_NO_STATIC_ENGINE) && \
+    !defined(OPENSSL_NO_DSO) && !defined(OPENSSL_USE_NODELETE)
 # ifdef DSO_WIN32
     {
         HMODULE handle = NULL;
@@ -285,7 +286,7 @@ DEFINE_RUN_ONCE_STATIC(ossl_init_engine_
     return 1;
 }
 # if !defined(OPENSSL_NO_HW) && \
-    (defined(__OpenBSD__) || defined(__FreeBSD__) || defined(HAVE_CRYPTODEV))
+    (defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(HAVE_CRYPTODEV))
 static CRYPTO_ONCE engine_cryptodev = CRYPTO_ONCE_STATIC_INIT;
 DEFINE_RUN_ONCE_STATIC(ossl_init_engine_cryptodev)
 {
@@ -616,7 +617,7 @@ int OPENSSL_init_crypto(uint64_t opts, c
             && !RUN_ONCE(&engine_openssl, ossl_init_engine_openssl))
         return 0;
 # if !defined(OPENSSL_NO_HW) && \
-    (defined(__OpenBSD__) || defined(__FreeBSD__) || defined(HAVE_CRYPTODEV))
+    (defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(HAVE_CRYPTODEV))
     if ((opts & OPENSSL_INIT_ENGINE_CRYPTODEV)
             && !RUN_ONCE(&engine_cryptodev, ossl_init_engine_cryptodev))
         return 0;
@@ -666,7 +667,8 @@ int OPENSSL_atexit(void (*handler)(void)
 {
     OPENSSL_INIT_STOP *newhand;
 
-#if !defined(OPENSSL_NO_DSO) && !defined(OPENSSL_USE_NODELETE)
+#if defined(OPENSSL_NO_STATIC_ENGINE) && \
+    !defined(OPENSSL_NO_DSO) && !defined(OPENSSL_USE_NODELETE)
     {
         union {
             void *sym;
