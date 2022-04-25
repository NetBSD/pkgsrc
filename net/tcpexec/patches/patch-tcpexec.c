$NetBSD: patch-tcpexec.c,v 1.2 2022/04/25 15:33:58 tnn Exp $

Fix build without close-on-exec and/or SO_REUSEPORT.

--- tcpexec.c.orig	2021-11-13 13:34:51.000000000 +0000
+++ tcpexec.c
@@ -152,6 +152,9 @@ static int tcpexec_listen(const char *ad
   }
 
   for (rp = res; rp != NULL; rp = rp->ai_next) {
+#ifndef SOCK_CLOEXEC
+#define SOCK_CLOEXEC 0
+#endif
     fd = socket(rp->ai_family, rp->ai_socktype | SOCK_CLOEXEC, rp->ai_protocol);
 
     if (fd == -1)
@@ -160,8 +163,10 @@ static int tcpexec_listen(const char *ad
     if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable)) == -1)
       return -1;
 
+#ifdef SO_REUSEPORT
     if (setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, &enable, sizeof(enable)) == -1)
       return -1;
+#endif
 
     if (bind(fd, rp->ai_addr, rp->ai_addrlen) == -1)
       return -1;
