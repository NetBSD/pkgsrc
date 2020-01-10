$NetBSD: patch-popper_pop__tls__openssl.c,v 1.2 2020/01/10 21:16:03 joerg Exp $

Disable SSLv2 and SSLv3. Don't look into the internals of SSL objects.

--- popper/pop_tls_openssl.c.orig	2011-05-30 19:13:40.000000000 +0000
+++ popper/pop_tls_openssl.c
@@ -51,6 +51,7 @@
 #include <fcntl.h>
 #include <setjmp.h>
 #include <signal.h>
+#include <string.h>
 
 #ifdef HAVE_UNISTD_H
 #  include <unistd.h>
@@ -318,6 +319,7 @@ openssl_init ( pop_tls *pTLS, POP *pPOP 
             pTLS->m_OpenSSLmeth = SSLv23_server_method();
             break;
 
+#if 0
         case QPOP_SSLv2:       /* SSL version 2 only */
             DEBUG_LOG0 ( pPOP, "...setting method to SSLv2_server_method" );
             pTLS->m_OpenSSLmeth = SSLv2_server_method();
@@ -327,6 +329,7 @@ openssl_init ( pop_tls *pTLS, POP *pPOP 
             DEBUG_LOG0 ( pPOP, "...setting method to SSLv3_server_method" );
             pTLS->m_OpenSSLmeth = SSLv3_server_method();
             break;
+#endif
 
         case QPOP_TLSv1:       /* TLS version 1 only */
             DEBUG_LOG0 ( pPOP, "...setting method to TLSv1_server_method" );
@@ -350,6 +353,7 @@ openssl_init ( pop_tls *pTLS, POP *pPOP 
         log_openssl_err ( pPOP, HERE, "Unable to allocate SSL_CTX" );
         goto Done;
     }
+    SSL_CTX_set_options(pTLS->m_OpenSSLctx, SSL_OP_NO_SSLv2);
 
     /*
      * Set desired options
@@ -537,7 +541,7 @@ openssl_handshake ( pop_tls *pTLS )
                           "%s session-id; cipher: %s (%s), %d bits",
                           VERSION, SSL_CIPHER_get_version(ciph),
                           pTLS->m_pPOP->client, pTLS->m_pPOP->ipaddr,
-                          ( pTLS->m_OpenSSLconn->hit ? "reused" : "new" ),
+                          ( SSL_session_reused(pTLS->m_OpenSSLconn) ? "reused" : "new" ),
                           ( ciph_name != NULL ? ciph_name : "(none)" ),
                           get_cipher_description ( ciph, buf, sizeof(buf) ),
                           SSL_CIPHER_get_bits    ( ciph, &al_bits ) );
