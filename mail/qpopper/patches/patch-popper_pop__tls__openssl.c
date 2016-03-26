$NetBSD: patch-popper_pop__tls__openssl.c,v 1.1 2016/03/26 23:52:37 joerg Exp $

Disable SSLv2.

--- popper/pop_tls_openssl.c.orig	2016-03-26 21:49:05.471963098 +0000
+++ popper/pop_tls_openssl.c
@@ -318,10 +318,12 @@ openssl_init ( pop_tls *pTLS, POP *pPOP 
             pTLS->m_OpenSSLmeth = SSLv23_server_method();
             break;
 
+#if 0
         case QPOP_SSLv2:       /* SSL version 2 only */
             DEBUG_LOG0 ( pPOP, "...setting method to SSLv2_server_method" );
             pTLS->m_OpenSSLmeth = SSLv2_server_method();
             break;
+#endif
 
         case QPOP_SSLv3:       /* SSL version 3 only */
             DEBUG_LOG0 ( pPOP, "...setting method to SSLv3_server_method" );
@@ -350,6 +352,7 @@ openssl_init ( pop_tls *pTLS, POP *pPOP 
         log_openssl_err ( pPOP, HERE, "Unable to allocate SSL_CTX" );
         goto Done;
     }
+    SSL_CTX_set_options(pTLS->m_OpenSSLctx, SSL_OP_NO_SSLv2);
 
     /*
      * Set desired options
