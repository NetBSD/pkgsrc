$NetBSD: patch-src_common_PubKey.c,v 1.1 2011/12/19 13:58:34 wiz Exp $

Adapt for changes in openssl.

--- src/common/PubKey.c.orig	2003-06-19 01:55:04.000000000 +0000
+++ src/common/PubKey.c
@@ -289,7 +289,7 @@ pubkey_GetEmail(PubKey *pk)
   case pk_X509:
     {
       X509 *x = pk->keys.x509_cert;
-      STACK* emails;
+      STACK_OF(OPENSSL_STRING)* emails;
       const char* email = 0;
 
       emails = X509_get1_email(x);
