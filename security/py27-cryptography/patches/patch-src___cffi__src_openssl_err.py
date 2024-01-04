$NetBSD: patch-src___cffi__src_openssl_err.py,v 1.1 2024/01/04 20:49:27 triaxx Exp $

Disable deprecated function with OpenSSL 3.x.

--- src/_cffi_src/openssl/err.py.orig	2021-02-07 16:39:35.000000000 +0000
+++ src/_cffi_src/openssl/err.py
@@ -46,4 +46,7 @@ int ERR_GET_REASON(unsigned long);
 """
 
 CUSTOMIZATIONS = """
+#if OPENSSL_VERSION_MAJOR >= 3
+int (*ERR_GET_FUNC)(unsigned long) = NULL;
+#endif
 """
