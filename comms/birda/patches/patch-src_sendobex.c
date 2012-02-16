$NetBSD: patch-src_sendobex.c,v 1.1 2012/02/16 16:40:34 hans Exp $

--- src/sendobex.c.orig	2005-11-14 08:57:16.000000000 +0100
+++ src/sendobex.c	2012-01-25 16:30:35.349985033 +0100
@@ -327,7 +327,11 @@ void createOBEXSender(int port)
     //struct sockaddr addr;
     //socklen_t len;
     fprintf(stderr, "Socket fd=%d\n", sc->socket);
+#ifdef __sun
+    error = fcntl(sc->socket, F_SETFL, O_NONBLOCK);
+#else
     error = fcntl(sc->socket, F_SETFL, O_NONBLOCK | O_ASYNC);
+#endif
     if (error == -1) {
       perror("Couldn't fcntl socket\n");
     }
