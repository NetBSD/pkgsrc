$NetBSD: patch-adb__auth__host.c,v 1.1 2024/09/21 13:14:58 abs Exp $

OpenSSL 1.1.x compatibility.
Use getter for rsa->n, suggested by
https://wiki.openssl.org/index.php/OpenSSL_1.1.0_Changes

--- adb_auth_host.c.orig	2014-10-22 00:46:49.000000000 +0000
+++ adb_auth_host.c
@@ -50,6 +50,18 @@
 #define ANDROID_PATH   ".android"
 #define ADB_KEY_FILE   "adbkey"
 
+#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER < 0x10100000L
+static inline void RSA_get0_key(const RSA *r,
+     const BIGNUM **n, const BIGNUM **e, const BIGNUM **d)
+{
+	if (n)
+		*n = r->n;
+	if (e)
+		*e = r->e;
+	if (d)
+		*d = r->d;
+}
+#endif
 
 struct adb_private_key {
     struct listnode node;
@@ -73,13 +85,17 @@ static int RSA_to_RSAPublicKey(RSA *rsa,
     BIGNUM* n = BN_new();
     BIGNUM* n0inv = BN_new();
 
+    const BIGNUM* getter1;
+    const BIGNUM* getter2;
+
     if (RSA_size(rsa) != RSANUMBYTES) {
         ret = 0;
         goto out;
     }
 
     BN_set_bit(r32, 32);
-    BN_copy(n, rsa->n);
+    RSA_get0_key(rsa, &getter1, NULL, NULL);
+    BN_copy(n, getter1);
     BN_set_bit(r, RSANUMWORDS * 32);
     BN_mod_sqr(rr, r, n, ctx);
     BN_div(NULL, rem, n, r32, ctx);
@@ -93,7 +109,8 @@ static int RSA_to_RSAPublicKey(RSA *rsa,
         BN_div(n, rem, n, r32, ctx);
         pkey->n[i] = BN_get_word(rem);
     }
-    pkey->exponent = BN_get_word(rsa->e);
+    RSA_get0_key(rsa, NULL, &getter2, NULL);
+    pkey->exponent = BN_get_word(getter2);
 
 out:
     BN_free(n0inv);
