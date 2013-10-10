$NetBSD: patch-src_sendobex.c,v 1.2 2013/10/10 00:02:17 joerg Exp $

--- src/sendobex.c.orig	2005-11-14 07:57:16.000000000 +0000
+++ src/sendobex.c
@@ -302,7 +302,7 @@ static int in_bind_ne(short port, int ty
   if (sd < 0)
     switch (sd) {
     case SYSCALL_ERROR:
-      fprintf(stderr, "in_bind_ne: bind", "port = %d, type = %s\n", 
+      fprintf(stderr, "in_bind_ne: bind port = %d, type = %s\n", 
 	      port, socket_type_name(type));
       /* NOTREACHED */
     case RESOLVER_ERROR:
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
