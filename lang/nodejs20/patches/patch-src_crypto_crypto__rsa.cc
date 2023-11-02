$NetBSD: patch-src_crypto_crypto__rsa.cc,v 1.1 2023/11/02 13:16:54 adam Exp $

Fix build with old OpenSSL 1.1.1d, as in NetBSD 9.0

--- src/crypto/crypto_rsa.cc.orig	2022-05-17 11:37:46.000000000 +0000
+++ src/crypto/crypto_rsa.cc
@@ -12,6 +12,30 @@
 #include <openssl/bn.h>
 #include <openssl/rsa.h>
 
+#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER <0x1010105fL
+struct rsa_st {
+  int pad;
+  int32_t version;
+  void *meth;
+  void *engine;
+  void *n;
+  void *e;
+  void *d;
+  void *p;
+  void *q;
+  void *dmp1;
+  void *dmq1;
+  void *iqmp;
+  void *prime_infos;
+  RSA_PSS_PARAMS *pss;
+};
+
+static const RSA_PSS_PARAMS *RSA_get0_pss_params(const RSA *r)
+{
+  return r->pss;
+}
+#endif
+
 namespace node {
 
 using v8::ArrayBuffer;
