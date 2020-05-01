$NetBSD: patch-src_lib_ecore__con_ecore__con__ssl.c,v 1.1 2020/05/01 00:11:52 joerg Exp $

Just fail when SSL3 is explicitly required.

--- src/lib/ecore_con/ecore_con_ssl.c.orig	2020-04-25 20:50:19.247977990 +0000
+++ src/lib/ecore_con/ecore_con_ssl.c
@@ -1560,11 +1560,7 @@ _ecore_con_ssl_server_prepare_openssl(Ec
      {
       case ECORE_CON_USE_SSL3:
       case ECORE_CON_USE_SSL3 | ECORE_CON_LOAD_CERT:
-        if (!svr->created)
-          SSL_ERROR_CHECK_GOTO_ERROR(!(svr->ssl_ctx = SSL_CTX_new(SSLv3_client_method())));
-        else
-          SSL_ERROR_CHECK_GOTO_ERROR(!(svr->ssl_ctx = SSL_CTX_new(SSLv3_server_method())));
-        break;
+        return ECORE_CON_SSL_ERROR_SERVER_INIT_FAILED;
 
       case ECORE_CON_USE_TLS:
       case ECORE_CON_USE_TLS | ECORE_CON_LOAD_CERT:
