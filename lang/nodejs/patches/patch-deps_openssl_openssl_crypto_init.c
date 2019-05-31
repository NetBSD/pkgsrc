$NetBSD: patch-deps_openssl_openssl_crypto_init.c,v 1.2 2019/05/31 20:52:00 adam Exp $

Pull fix from https://github.com/nodejs/node/pull/21848/commits/9868d403221bc9d566cb88a37510a182b7fbad3b

--- deps/openssl/openssl/crypto/init.c.orig	2019-05-28 21:32:16.000000000 +0000
+++ deps/openssl/openssl/crypto/init.c
@@ -161,7 +161,7 @@ DEFINE_RUN_ONCE_STATIC(ossl_init_load_cr
 #ifdef OPENSSL_INIT_DEBUG
     fprintf(stderr, "OPENSSL_INIT: ossl_init_load_crypto_nodelete()\n");
 #endif
-#if !defined(OPENSSL_NO_DSO) \
+#if defined(OPENSSL_NO_STATIC_ENGINE) && !defined(OPENSSL_NO_DSO) \
     && !defined(OPENSSL_USE_NODELETE) \
     && !defined(OPENSSL_NO_PINSHARED)
 # ifdef DSO_WIN32
@@ -764,7 +764,7 @@ int OPENSSL_atexit(void (*handler)(void)
 {
     OPENSSL_INIT_STOP *newhand;
 
-#if !defined(OPENSSL_NO_DSO) \
+#if defined(OPENSSL_NO_STATIC_ENGINE) && !defined(OPENSSL_NO_DSO) \
     && !defined(OPENSSL_USE_NODELETE)\
     && !defined(OPENSSL_NO_PINSHARED)
     {
