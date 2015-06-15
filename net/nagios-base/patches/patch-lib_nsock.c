$NetBSD: patch-lib_nsock.c,v 1.1 2015/06/15 01:29:40 rodent Exp $

--- lib/nsock.c.orig	2014-08-12 15:00:01.000000000 +0000
+++ lib/nsock.c
@@ -81,7 +81,7 @@ int nsock_unix(const char *path, unsigne
 	if(flags & NSOCK_UDP)
 		return sock;
 
-	if(listen(sock, 3) < 0) {
+	if(listen(sock, 128) < 0) {
 		close(sock);
 		return NSOCK_ELISTEN;
 	}
