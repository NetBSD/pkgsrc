$NetBSD: patch-fix-socklen_t-types-main.c,v 1.1 2020/04/17 11:28:02 tm Exp $

Fix socklen_t types

Richard Laager <rlaager@wiktel.com>
https://sourceforge.net/p/squirrelmail/mailman/message/35526927/

--- src/main.c.orig
+++ src/main.c
@@ -285,7 +285,7 @@
     char f_randfile[ PATH_MAX ];
     int listensd;                      /* socket descriptor we'll bind to */
     long clientsd;                     /* incoming socket descriptor */
-    int sockaddrlen;                       
+    socklen_t sockaddrlen;
     struct sockaddr_storage srvaddr;
     struct sockaddr_storage cliaddr;
     pthread_t ThreadId;                /* thread id of each incoming conn */
