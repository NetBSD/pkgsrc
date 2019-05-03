$NetBSD: patch-openssl__compat.h,v 1.1 2019/05/03 11:04:34 hauke Exp $

Provide compatibility shims for building with openssl 1.0

--- openssl_compat.h.orig	2019-05-03 10:46:27.814125691 +0000
+++ openssl_compat.h
@@ -0,0 +1,18 @@
+/*
+ * OpenSSL Compatibility Shims for pre-1.1.0
+ *
+*/
+#ifndef RADMIND_OPENSSL_SHIMS
+#define RADMIND_OPENSSL_SHIMS
+
+#include <openssl/opensslv.h>
+
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#include <string.h>
+#include <openssl/engine.h>
+
+EVP_MD_CTX *EVP_MD_CTX_new(void);
+void EVP_MD_CTX_free(EVP_MD_CTX *ctx);
+
+#endif /* OPENSSL_VERSION_NUMBER */
+#endif /* RADMIND_OPENSSL_SHIMS */
