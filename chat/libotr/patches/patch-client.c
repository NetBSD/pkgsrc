$NetBSD: patch-client.c,v 1.1 2023/01/04 18:46:09 vins Exp $

Provide a declaration of listen()

--- tests/regression/client/client.c.orig	2015-12-25 17:39:45.000000000 +0000
+++ tests/regression/client/client.c
@@ -26,6 +26,7 @@
 #include <stdlib.h>
 #include <syscall.h>
 #include <sys/epoll.h>
+#include <sys/socket.h> 
 #include <sys/types.h>
 #include <sys/un.h>
 #include <unistd.h>
