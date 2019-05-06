$NetBSD: patch-lib_crypto_builtin_pbkdf2.c,v 1.2 2019/05/06 14:06:05 wiz Exp $

Fix conflict with hmac() symbol in libc.
https://github.com/krb5/krb5/pull/926

--- lib/crypto/builtin/pbkdf2.c.orig	2018-11-01 23:51:07.000000000 +0000
+++ lib/crypto/builtin/pbkdf2.c
@@ -75,7 +75,7 @@ static void printd (const char *descr, k
  * index appended to the original salt.
  */
 static krb5_error_code
-hmac(const struct krb5_hash_provider *hash, krb5_keyblock *pass,
+krb5_hmac(const struct krb5_hash_provider *hash, krb5_keyblock *pass,
      krb5_data *salt, krb5_data *out)
 {
     krb5_error_code err;
@@ -123,7 +123,7 @@ F(char *output, char *u_tmp1, char *u_tm
 #if 0
     printf("F: computing hmac #1 (U_1) with %s\n", pdata.contents);
 #endif
-    err = hmac(hash, pass, &sdata, &out);
+    err = krb5_hmac(hash, pass, &sdata, &out);
     if (err)
         return err;
 #if 0
@@ -138,7 +138,7 @@ F(char *output, char *u_tmp1, char *u_tm
         printf("F: computing hmac #%d (U_%d)\n", j, j);
 #endif
         memcpy(u_tmp2, u_tmp1, hlen);
-        err = hmac(hash, pass, &sdata, &out);
+        err = krb5_hmac(hash, pass, &sdata, &out);
         if (err)
             return err;
 #if 0
