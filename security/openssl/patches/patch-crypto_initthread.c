$NetBSD: patch-crypto_initthread.c,v 1.1 2026/01/28 18:14:41 adam Exp $

Fix crash on NetBSD.

--- crypto/initthread.c.orig	2026-01-28 18:08:51.781190168 +0000
+++ crypto/initthread.c
@@ -237,7 +237,7 @@ static void init_thread_destructor(void
 }
 
 static CRYPTO_ONCE ossl_init_thread_runonce = CRYPTO_ONCE_STATIC_INIT;
-static CRYPTO_THREAD_ID recursion_guard = (CRYPTO_THREAD_ID)-1;
+static CRYPTO_THREAD_ID recursion_guard = (CRYPTO_THREAD_ID)0;
 
 DEFINE_RUN_ONCE_STATIC(ossl_init_thread_once)
 {
