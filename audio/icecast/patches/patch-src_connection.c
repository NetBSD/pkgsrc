$NetBSD: patch-src_connection.c,v 1.1 2018/12/20 15:42:14 wiz Exp $

Check some return values, fixes core dump when ssl_ctx is NULL.

--- src/connection.c.orig	2015-12-27 16:46:32.000000000 +0000
+++ src/connection.c
@@ -202,7 +202,15 @@ static void get_ssl_certificate (ice_con
     SSL_library_init();                      /* initialize library */
 
     method = SSLv23_server_method();
+    if (method == NULL) {
+	ICECAST_LOG_INFO("No SSL capability on any configured ports"); 
+	return;
+    }
     ssl_ctx = SSL_CTX_new (method);
+    if (ssl_ctx == NULL) {
+	ICECAST_LOG_INFO("No SSL capability on any configured ports"); 
+	return;
+    }
     ssl_opts = SSL_CTX_get_options (ssl_ctx);
 #ifdef SSL_OP_NO_COMPRESSION
     SSL_CTX_set_options (ssl_ctx, ssl_opts|SSL_OP_NO_SSLv2|SSL_OP_NO_SSLv3|SSL_OP_NO_COMPRESSION);
