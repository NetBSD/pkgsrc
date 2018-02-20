$NetBSD: patch-socket.c,v 1.1 2018/02/20 13:19:39 wiz Exp $

Fix build with openssl-1.1.

--- socket.c.orig	2012-08-13 20:02:41.000000000 +0000
+++ socket.c
@@ -880,8 +880,10 @@ int SSLOpen(int sock, char *mycert, char
 			report(stderr, GT_("Your operating system does not support SSLv2.\n"));
 			return -1;
 #endif
+#if defined(SSLv3_client_method)
 		} else if(!strcasecmp("ssl3",myproto)) {
 			_ctx[sock] = SSL_CTX_new(SSLv3_client_method());
+#endif
 		} else if(!strcasecmp("tls1",myproto)) {
 			_ctx[sock] = SSL_CTX_new(TLSv1_client_method());
 		} else if (!strcasecmp("ssl23",myproto)) {
