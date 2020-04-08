$NetBSD: patch-ak,v 1.2 2020/04/08 15:22:07 rhialto Exp $

- Use version-flexible SSL/TLS method.

--- ckuus7.c.orig	2011-06-23 16:13:11.000000000 +0000
+++ ckuus7.c
@@ -32,6 +32,8 @@
 #include "ckucmd.h"
 #include "ckclib.h"
 
+#include <errno.h>
+
 #ifdef VMS
 #ifndef TCPSOCKET
 #include <errno.h>
@@ -14340,7 +14342,7 @@ sho_auth(cx) int cx; {
             if (ssl_con == NULL) {
                 SSL_library_init();
                 ssl_ctx = (SSL_CTX *)
-                  SSL_CTX_new((SSL_METHOD *)TLSv1_method());
+                  SSL_CTX_new((SSL_METHOD *)SSLv23_method());
                 if (ssl_ctx != NULL)
                   ssl_con= (SSL *) SSL_new(ssl_ctx);
             }
