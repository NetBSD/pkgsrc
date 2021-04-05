$NetBSD: patch-liboriutil_key.cc,v 1.1 2021/04/05 07:51:36 nia Exp $

OpenSSL 1.1 support.

--- liboriutil/key.cc.orig	2019-01-28 01:12:19.000000000 +0000
+++ liboriutil/key.cc
@@ -131,7 +131,7 @@ PublicKey::verify(const string &blob,
                   const string &digest) const
 {
     int err;
-    EVP_MD_CTX * ctx = new EVP_MD_CTX(); // XXX: openssl 1.1+ EVP_MD_CTX_new();
+    EVP_MD_CTX * ctx = EVP_MD_CTX_new();
     if (!ctx) {
       throw system_error(ENOMEM, std::generic_category(), "Could not allocate EVP_MD_CTX");
       return false;
@@ -146,14 +146,14 @@ PublicKey::verify(const string &blob,
     if (err != 1)
     {
         ERR_print_errors_fp(stderr);
-        delete ctx; // XXX: openssl 1.1+ EVP_MD_CTX_free(ctx);
+        EVP_MD_CTX_free(ctx);
         throw exception();
         return false;
     }
 
     // Prepend 8-byte public key digest
 
-    delete ctx; // XXX: openssl 1.1+ EVP_MD_CTX_free(ctx);
+    EVP_MD_CTX_free(ctx);
     return true;
 }
 
@@ -191,7 +191,7 @@ PrivateKey::sign(const string &blob) con
     int err;
     unsigned int sigLen = SIGBUF_LEN;
     char sigBuf[SIGBUF_LEN];
-    EVP_MD_CTX * ctx = new EVP_MD_CTX(); // XXX: openssl 1.1+ EVP_MD_CTX_new();
+    EVP_MD_CTX * ctx = EVP_MD_CTX_new();
     if (!ctx) {
       throw system_error(ENOMEM, std::generic_category(), "Could not allocate EVP_MD_CTX");
     }
@@ -202,13 +202,13 @@ PrivateKey::sign(const string &blob) con
     if (err != 1)
     {
         ERR_print_errors_fp(stderr);
-        delete ctx; // XXX: openssl 1.1+ EVP_MD_CTX_free(ctx);
+        EVP_MD_CTX_free(ctx);
         throw exception();
     }
 
     // XXX: Prepend 8-byte public key digest
 
-    delete ctx; // XXX: openssl 1.1+ EVP_MD_CTX_free(ctx);
+    EVP_MD_CTX_free(ctx);
     return string().assign(sigBuf, sigLen);
 }
 
