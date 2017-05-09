$NetBSD: patch-src_connection.c,v 1.3 2017/05/09 14:17:07 wiedi Exp $

accept4 needs SOCK_NONBLOCK as flag
upstream commit: https://github.com/dlundquist/sniproxy/commit/ce0ab17aa7bd709c34dee8fd235f35321a3ada91

--- src/connection.c.orig	2017-04-26 14:22:08.000000000 +0000
+++ src/connection.c
@@ -111,7 +111,7 @@ accept_connection(struct Listener *liste
     int sockfd = accept4(listener->watcher.fd,
                     (struct sockaddr *)&con->client.addr,
                     &con->client.addr_len,
-                    O_NONBLOCK);
+                    SOCK_NONBLOCK);
 #else
     int sockfd = accept(listener->watcher.fd,
                     (struct sockaddr *)&con->client.addr,
