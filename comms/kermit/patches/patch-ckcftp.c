$NetBSD: patch-ckcftp.c,v 1.1 2020/04/08 16:22:00 rhialto Exp $

Use SSLv23_client_method() because it is version-flexible.
The difference that Kermit makes between SSL and TLS is gone.

--- ckcftp.c.orig	2011-07-14 18:17:30.000000000 +0200
+++ ckcftp.c	2020-04-06 17:01:35.943676852 +0200
@@ -10196,19 +10196,19 @@
 #define SSL_OP_DONT_INSERT_EMPTY_FRAGMENTS 0L
 #endif
     if (auth_type && !strcmp(auth_type,"TLS")) {
-        ssl_ftp_ctx=SSL_CTX_new(SSLv3_client_method());
+        ssl_ftp_ctx=SSL_CTX_new(SSLv23_client_method());
         if (!ssl_ftp_ctx)
           return(0);
         SSL_CTX_set_options(ssl_ftp_ctx,
                             SSL_OP_SINGLE_DH_USE|SSL_OP_EPHEMERAL_RSA
                             );
     } else {
-        ssl_ftp_ctx = SSL_CTX_new(ftp_bug_use_ssl_v2 ? SSLv23_client_method() : 
-                                  SSLv3_client_method());
+        ssl_ftp_ctx = SSL_CTX_new(SSLv23_client_method());
         if (!ssl_ftp_ctx)
           return(0);
         SSL_CTX_set_options(ssl_ftp_ctx,
-                            (ftp_bug_use_ssl_v2 ? 0 : SSL_OP_NO_SSLv2)|
+                            
+                            (ftp_bug_use_ssl_v2 ? 0 : SSL_OP_NO_SSLv2/*|SSL_OP_NO_SSLv3*/)|
                             SSL_OP_SINGLE_DH_USE|SSL_OP_EPHEMERAL_RSA
                             );
     }
