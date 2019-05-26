$NetBSD: patch-src_openssl.c,v 1.1 2019/05/26 18:10:49 leot Exp $

Backport upstream commit 14e3712b8c39165219fa227bd11f6feae7b09a33:

src/openssl.c: fix ssl_init for openssl 1.1.1

ssl_init fails with openssl 1.1.1 when openssl.cnf is not found.
Redundant calls to intialization functions were removed as
OPENSSL_config takes care of them for openssl versions < 1.1.0.
For versions > 1.1.0, OPENSSL_init_ssl is preferred.

--- src/openssl.c.orig	2019-04-05 09:58:33.000000000 +0000
+++ src/openssl.c
@@ -174,7 +174,9 @@ ssl_init (void)
 #if OPENSSL_VERSION_NUMBER >= 0x00907000
   if (ssl_true_initialized == 0)
     {
-#if OPENSSL_API_COMPAT < 0x10100000L
+#if !defined(LIBRESSL_VERSION_NUMBER) && (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+      OPENSSL_init_ssl (OPENSSL_INIT_LOAD_CONFIG | OPENSSL_INIT_ENGINE_ALL_BUILTIN, NULL);
+#else
       OPENSSL_config (NULL);
 #endif
       ssl_true_initialized = 1;
@@ -194,21 +196,9 @@ ssl_init (void)
       goto error;
     }
 
-#if OPENSSL_VERSION_NUMBER >= 0x00907000
-  OPENSSL_load_builtin_modules();
-#ifndef OPENSSL_NO_ENGINE
-  ENGINE_load_builtin_engines();
-#endif
-  CONF_modules_load_file(NULL, NULL,
-      CONF_MFLAGS_DEFAULT_SECTION|CONF_MFLAGS_IGNORE_MISSING_FILE);
-#endif
-#if OPENSSL_API_COMPAT >= 0x10100000L
-  OPENSSL_init_ssl(0, NULL);
-#else
+#if defined(LIBRESSL_VERSION_NUMBER) || (OPENSSL_VERSION_NUMBER < 0x10100000L)
   SSL_library_init ();
   SSL_load_error_strings ();
-#endif
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
   SSLeay_add_all_algorithms ();
   SSLeay_add_ssl_algorithms ();
 #endif
