$NetBSD: patch-openssl__compat.c,v 1.1 2019/05/03 11:04:34 hauke Exp $

Provide compatibility shims for building with openssl 1.0

--- openssl_compat.c.orig	2019-05-03 10:46:27.805935157 +0000
+++ openssl_compat.c
@@ -0,0 +1,31 @@
+/*
+ * OpenSSL Compatibility Shims for pre-1.1.0
+ *
+*/
+#include <string.h>
+#include <openssl/engine.h>
+#include "openssl_compat.h"
+
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+
+static void *OPENSSL_zalloc(size_t num)
+{
+   void *ret = OPENSSL_malloc(num);
+
+   if (ret != NULL)
+       memset(ret, 0, num);
+   return ret;
+}
+
+EVP_MD_CTX *EVP_MD_CTX_new(void)
+{
+    return OPENSSL_zalloc(sizeof(EVP_MD_CTX));
+}
+
+void EVP_MD_CTX_free(EVP_MD_CTX *ctx)
+{
+   EVP_MD_CTX_cleanup(ctx);
+   OPENSSL_free(ctx);
+}
+
+#endif /* OPENSSL_VERSION_NUMBER */
