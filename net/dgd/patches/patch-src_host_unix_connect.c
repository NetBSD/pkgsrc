$NetBSD: patch-src_host_unix_connect.c,v 1.1 2024/10/11 07:02:12 nia Exp $

Use standard spelling of FNDELAY.

--- src/host/unix/connect.c.orig	2024-10-11 07:00:06.908535425 +0000
+++ src/host/unix/connect.c
@@ -3,8 +3,10 @@
 # include <netinet/in.h>
 # include <arpa/inet.h>
 # include <netdb.h>
+# include <fcntl.h>
 # include <signal.h>
 # include <errno.h>
+# include <unistd.h>
 # define INCLUDE_FILE_IO
 # include "dgd.h"
 # include "comm.h"
@@ -507,9 +509,9 @@ void conn_listen()
 {
     if (listen(telnet, 64) < 0 || listen(binary, 64) < 0) {
 	perror("listen");
-    } else if (fcntl(telnet, F_SETFL, FNDELAY) < 0 ||
-	       fcntl(binary, F_SETFL, FNDELAY) < 0 ||
-	       fcntl(udp, F_SETFL, FNDELAY) < 0) {
+    } else if (fcntl(telnet, F_SETFL, O_NONBLOCK) < 0 ||
+	       fcntl(binary, F_SETFL, O_NONBLOCK) < 0 ||
+	       fcntl(udp, F_SETFL, O_NONBLOCK) < 0) {
 	perror("fcntl");
     } else {
 	return;
@@ -535,7 +537,7 @@ connection *conn_tnew()
     if (fd < 0) {
 	return (connection *) NULL;
     }
-    fcntl(fd, F_SETFL, FNDELAY);
+    fcntl(fd, F_SETFL, O_NONBLOCK);
 
     conn = flist;
     flist = conn->next;
@@ -572,7 +574,7 @@ connection *conn_bnew()
     if (fd < 0) {
 	return (connection *) NULL;
     }
-    fcntl(fd, F_SETFL, FNDELAY);
+    fcntl(fd, F_SETFL, O_NONBLOCK);
 
     conn = flist;
     flist = conn->next;
