$NetBSD: patch-src_ccrtp_crypto_gcrypt_InitializeGcrypt.cpp,v 1.1 2014/02/21 20:30:27 joerg Exp $

--- src/ccrtp/crypto/gcrypt/InitializeGcrypt.cpp.orig	2012-06-18 15:19:04.000000000 +0000
+++ src/ccrtp/crypto/gcrypt/InitializeGcrypt.cpp
@@ -52,9 +52,7 @@ static int gcry_pthread_mutex_unlock (vo
 { return pthread_mutex_unlock ((pthread_mutex_t *)*lock); }                   \
                                                                               \
 static struct gcry_thread_cbs gcry_threads_pthread =                          \
-{ GCRY_THREAD_OPTION_PTHREAD, NULL,                                           \
-  gcry_pthread_mutex_init, gcry_pthread_mutex_destroy,                        \
-  gcry_pthread_mutex_lock, gcry_pthread_mutex_unlock }
+{ GCRY_THREAD_OPTION_PTHREAD }
 
 /** Implement the locking callback functions for libgcrypt.
  *
