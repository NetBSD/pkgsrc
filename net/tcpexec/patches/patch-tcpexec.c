$NetBSD: patch-tcpexec.c,v 1.1 2021/11/15 11:36:58 schmonz Exp $

Fix macOS build.

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
