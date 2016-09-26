$NetBSD: patch-crypto_kernel_crypto__kernel.c,v 1.1 2016/09/26 13:20:41 maya Exp $

avoid conflict with builtin hmac on netbsd-7.99.x

--- crypto/kernel/crypto_kernel.c.orig	2016-09-21 15:54:48.158697000 +0000
+++ crypto/kernel/crypto_kernel.c
@@ -77,7 +77,7 @@ extern cipher_type_t aes_cbc;
  */
 
 extern auth_type_t null_auth;
-extern auth_type_t hmac;
+extern auth_type_t local_hmac;
 
 /* crypto_kernel is a global variable, the only one of its datatype */
 
@@ -162,7 +162,7 @@ crypto_kernel_init() {
   status = crypto_kernel_load_auth_type(&null_auth, NULL_AUTH);
   if (status)
     return status;
-  status = crypto_kernel_load_auth_type(&hmac, HMAC_SHA1);
+  status = crypto_kernel_load_auth_type(&local_hmac, HMAC_SHA1);
   if (status)
     return status;
 
