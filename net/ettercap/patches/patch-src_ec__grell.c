$NetBSD: patch-src_ec__grell.c,v 1.1 2016/03/29 21:59:15 khorben Exp $

--- src/ec_grell.c.orig	2003-07-10 08:59:09.000000000 +0000
+++ src/ec_grell.c
@@ -447,11 +447,13 @@ static int server_init(char *buf, size_t
 
       if (SSL_connect(son_data->ssl_server)!=1)
       {
+#ifndef OPENSSL_NO_SSL2
          son_data->ssl_ctx_server = SSL_CTX_new(SSLv2_client_method());
          son_data->ssl_server = SSL_new(son_data->ssl_ctx_server);
          SSL_set_connect_state(son_data->ssl_server);
          SSL_set_fd(son_data->ssl_server, son_data->server_fd);
          if (SSL_connect(son_data->ssl_server)!=1)
+#endif
          {
             son_data->ssl_ctx_server = SSL_CTX_new(TLSv1_client_method());
             son_data->ssl_server = SSL_new(son_data->ssl_ctx_server);
