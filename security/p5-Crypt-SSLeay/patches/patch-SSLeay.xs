$NetBSD: patch-SSLeay.xs,v 1.1 2020/09/08 12:19:10 wiz Exp $

openssl 1.1 compat from https://rt.cpan.org/Public/Bug/Display.html?id=118343.

--- SSLeay.xs.orig	2014-04-23 22:36:24.000000000 +0000
+++ SSLeay.xs
@@ -149,15 +149,15 @@ SSL_CTX_new(packname, ssl_version)
             ctx = SSL_CTX_new(SSLv23_client_method());
         }
         else if(ssl_version == 3) {
-            ctx = SSL_CTX_new(SSLv3_client_method());
+            ctx = SSL_CTX_new(TLS_client_method());
         }
         else {
-#ifndef OPENSSL_NO_SSL2
+#if !defined(OPENSSL_NO_SSL2) && OPENSSL_VERSION_NUMBER < 0x10100000L
             /* v2 is the default */
             ctx = SSL_CTX_new(SSLv2_client_method());
 #else
             /* v3 is the default */
-            ctx = SSL_CTX_new(SSLv3_client_method());
+            ctx = SSL_CTX_new(TLS_client_method());
 #endif
         }
 
