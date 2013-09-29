$NetBSD: patch-webmitm.c,v 1.1 2013/09/29 10:19:01 joerg Exp $

--- webmitm.c.orig	2013-09-28 13:09:07.000000000 +0000
+++ webmitm.c
@@ -43,6 +43,7 @@ int	 http_fd, https_fd;
 int	 client_fd, server_fd;
 SSL_CTX	*ssl_client_ctx, *ssl_server_ctx;
 SSL	*ssl_client, *ssl_server;
+#define csin my_csin
 struct	 sockaddr_in csin, ssin;
 int	 do_ssl, sig_pipe[2];
 
