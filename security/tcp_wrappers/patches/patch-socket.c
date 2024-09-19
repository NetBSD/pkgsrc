$NetBSD: patch-socket.c,v 1.1 2024/09/19 16:46:44 tnn Exp $

Include arpa/inet.h for inet_pton(3)

--- socket.c.orig	2024-09-19 16:43:43.630481893 +0000
+++ socket.c
@@ -29,6 +29,7 @@ static char sccsid[] = "@(#) socket.c 1.
 #include <stdio.h>
 #include <syslog.h>
 #include <string.h>
+#include <arpa/inet.h>
 
 extern char *inet_ntoa();
 
