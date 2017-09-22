$NetBSD: patch-crypto_x509v3_v3_addr.c,v 1.1 2017/09/22 21:02:43 tez Exp $

Patch for CVE-2017-3735 from 
https://github.com/openssl/openssl/commit/31c8b265591a0aaa462a1f3eb5770661aaac67db


--- crypto/x509v3/v3_addr.c
+++ crypto/x509v3/v3_addr.c
@@ -130,10 +130,12 @@ static int length_from_afi(const unsigned afi)
  */
 unsigned int v3_addr_get_afi(const IPAddressFamily *f)
 {
-    return ((f != NULL &&
-             f->addressFamily != NULL && f->addressFamily->data != NULL)
-            ? ((f->addressFamily->data[0] << 8) | (f->addressFamily->data[1]))
-            : 0);
+    if (f == NULL
+            || f->addressFamily == NULL
+            || f->addressFamily->data == NULL
+            || f->addressFamily->length < 2)
+        return 0;
+    return (f->addressFamily->data[0] << 8) | f->addressFamily->data[1];
 }
 
 /*
