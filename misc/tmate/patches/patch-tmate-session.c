$NetBSD: patch-tmate-session.c,v 1.1 2019/12/19 22:21:01 joerg Exp $

--- tmate-session.c.orig	2019-12-19 18:49:04.116108537 +0000
+++ tmate-session.c
@@ -3,6 +3,7 @@
 #include <event2/event.h>
 
 #include <sys/socket.h>
+#include <netinet/in.h>
 
 #include <stdio.h>
 #include <stdlib.h>
