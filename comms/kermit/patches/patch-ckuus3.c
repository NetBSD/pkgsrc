$NetBSD: patch-ckuus3.c,v 1.1 2020/04/08 15:22:07 rhialto Exp $

Use version-flexible method.

--- ckuus3.c.orig	2011-06-26 18:20:07.000000000 +0000
+++ ckuus3.c
@@ -13048,7 +13048,7 @@ case XYDEBU:                            
                       if (ssl_con == NULL) {
                           SSL_library_init();
                           ssl_ctx = (SSL_CTX *)
-                            SSL_CTX_new((SSL_METHOD *)TLSv1_method());
+                            SSL_CTX_new((SSL_METHOD *)SSLv23_method());
                           if (ssl_ctx != NULL)
                             ssl_con= (SSL *) SSL_new(ssl_ctx);
                       }
