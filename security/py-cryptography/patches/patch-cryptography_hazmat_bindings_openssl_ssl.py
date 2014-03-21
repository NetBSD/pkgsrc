$NetBSD: patch-cryptography_hazmat_bindings_openssl_ssl.py,v 1.1 2014/03/21 15:14:21 wiz Exp $

Fixes linkage on NetBSD-current up to the version that has openssl fixed
to include d1_meth.c.
Based on upstream patch from
https://gist.github.com/reaperhulk/5e4d3d30ac1598473206

--- cryptography/hazmat/bindings/openssl/ssl.py.orig	2014-03-04 01:53:14.000000000 +0000
+++ cryptography/hazmat/bindings/openssl/ssl.py
@@ -37,6 +37,7 @@ static const int Cryptography_HAS_RELEAS
 static const int Cryptography_HAS_OP_NO_COMPRESSION;
 
 static const int Cryptography_HAS_SSL_OP_MSIE_SSLV2_RSA_PADDING;
+static const long Cryptography_HAS_NETBSD_D1_METH;
 
 static const int SSL_FILETYPE_PEM;
 static const int SSL_FILETYPE_ASN1;
@@ -365,6 +366,19 @@ const long SSL_OP_MSIE_SSLV2_RSA_PADDING
 #ifdef OPENSSL_NO_EC
 long (*SSL_CTX_set_tmp_ecdh)(SSL_CTX *, EC_KEY *) = NULL;
 #endif
+
+// NetBSD shipped without including d1_meth.c. Sad trombone.
+#ifdef __NetBSD__
+#  include <sys/param.h>
+#  if (__NetBSD_Version__ < 699003800)
+static const long Cryptography_HAS_NETBSD_D1_METH = 0;
+const SSL_METHOD* DTLSv1_method(void) { return NULL; };
+#  else
+static const long Cryptography_HAS_NETBSD_D1_METH = 1;
+#  endif
+#else
+static const long Cryptography_HAS_NETBSD_D1_METH = 1;
+#endif
 """
 
 CONDITIONAL_NAMES = {
@@ -408,5 +422,9 @@ CONDITIONAL_NAMES = {
 
     "Cryptography_HAS_EC": [
         "SSL_CTX_set_tmp_ecdh",
-    ]
+    ],
+
+    "Cryptography_HAS_NETBSD_D1_METH": [
+        "DTLSv1_method",
+    ],
 }
