$NetBSD: patch-connect.c,v 1.1 2018/12/02 00:48:46 leot Exp $

Use SNI extension, from Tomasz Miasko in GitHub issue 50.

From upstream commit dde4c369359dc12bfe93329f3df9c9dfd2e3837d.

--- connect.c.orig	2018-12-02 00:37:55.540662771 +0000
+++ connect.c
@@ -584,6 +584,11 @@ makessl(struct server *srv, int fd, int 
 		goto error;
 	}
 
+	if (SSL_set_tlsext_host_name(ssl, srv->host) != 1) {
+		*cause = sslerror("SSL_set_tlsext_host_name");
+		goto error;
+	}
+
 	if (SSL_set_fd(ssl, fd) != 1) {
 		*cause = sslerror("SSL_set_fd");
 		goto error;
