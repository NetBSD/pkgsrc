$NetBSD: patch-src_drv__imap.c,v 1.1 2020/06/12 13:46:22 ryoon Exp $

* Google's Gmail access token is longer than 80 bytes.

--- src/drv_imap.c.orig	2019-03-10 10:27:55.000000000 +0000
+++ src/drv_imap.c
@@ -1867,7 +1867,7 @@ ensure_password( imap_server_conf_t *srv
 	if (cmd) {
 		FILE *fp;
 		int ret;
-		char buffer[80];
+		char buffer[1024];
 
 		if (*cmd == '+') {
 			flushn();
