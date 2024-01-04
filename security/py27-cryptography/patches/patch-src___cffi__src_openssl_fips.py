$NetBSD: patch-src___cffi__src_openssl_fips.py,v 1.1 2024/01/04 20:49:27 triaxx Exp $

Disable deprecated function with OpenSSL 3.x.

--- src/_cffi_src/openssl/fips.py.orig	2021-02-07 16:39:35.000000000 +0000
+++ src/_cffi_src/openssl/fips.py
@@ -18,7 +18,7 @@ int FIPS_mode(void);
 """
 
 CUSTOMIZATIONS = """
-#if CRYPTOGRAPHY_IS_LIBRESSL
+#if CRYPTOGRAPHY_IS_LIBRESSL || OPENSSL_VERSION_MAJOR >= 3
 static const long Cryptography_HAS_FIPS = 0;
 int (*FIPS_mode_set)(int) = NULL;
 int (*FIPS_mode)(void) = NULL;
