$NetBSD: patch-sshmitm.c,v 1.1 2013/09/29 10:19:01 joerg Exp $

--- sshmitm.c.orig	2013-09-28 13:07:42.000000000 +0000
+++ sshmitm.c
@@ -41,6 +41,7 @@ int	 mitm_fd;
 int	 client_fd, server_fd;
 SSH_CTX	*ssh_client_ctx, *ssh_server_ctx;
 SSH	*ssh_client, *ssh_server;
+#define csin my_csin
 struct	 sockaddr_in csin, ssin;
 int	 sig_pipe[2];
 
