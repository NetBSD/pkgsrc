$NetBSD: patch-util_ulockmgr__server.c,v 1.1 2023/09/07 19:38:15 vins Exp $

Do not define closefrom() if libc provides it.

--- util/ulockmgr_server.c.orig	2019-01-04 13:38:34.000000000 +0000
+++ util/ulockmgr_server.c
@@ -22,6 +22,10 @@
 #include <sys/socket.h>
 #include <sys/wait.h>
 
+#ifdef HAVE_CONFIG_H
+	#include "config.h"
+#endif
+
 struct message {
 	unsigned intr : 1;
 	unsigned nofd : 1;
@@ -124,6 +128,7 @@ static int receive_message(int sock, voi
 	return res;
 }
 
+#if !defined(HAVE_CLOSEFROM)
 static int closefrom(int minfd)
 {
 	DIR *dir = opendir("/proc/self/fd");
@@ -141,6 +146,7 @@ static int closefrom(int minfd)
 	}
 	return 0;
 }
+#endif
 
 static void send_reply(int cfd, struct message *msg)
 {
