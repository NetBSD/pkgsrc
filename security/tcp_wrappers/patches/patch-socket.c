$NetBSD: patch-socket.c,v 1.2 2025/04/29 14:18:00 tnn Exp $

Include arpa/inet.h for inet_pton(3)

--- socket.c.orig	1999-10-27 13:23:14.000000000 +0000
+++ socket.c
@@ -29,8 +29,7 @@ static char sccsid[] = "@(#) socket.c 1.
 #include <stdio.h>
 #include <syslog.h>
 #include <string.h>
-
-extern char *inet_ntoa();
+#include <arpa/inet.h>
 
 /* Local stuff. */
 
@@ -38,7 +37,7 @@ extern char *inet_ntoa();
 
 /* Forward declarations. */
 
-static void sock_sink();
+static void sock_sink(int);
 
 #ifdef APPEND_DOT
 
