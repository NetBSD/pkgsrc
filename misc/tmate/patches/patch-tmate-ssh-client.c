$NetBSD: patch-tmate-ssh-client.c,v 1.1 2019/12/19 22:21:01 joerg Exp $

--- tmate-ssh-client.c.orig	2019-12-19 18:48:37.085517987 +0000
+++ tmate-ssh-client.c
@@ -1,4 +1,5 @@
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <stdio.h>
 #include <event.h>
