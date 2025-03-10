$NetBSD: patch-table__socketmap.c,v 1.1 2025/03/10 05:44:52 vins Exp $

Rename local variables to avoid name clash on SunOS.

--- table_socketmap.c.orig	2024-11-03 12:42:12.000000000 +0000
+++ table_socketmap.c
@@ -53,22 +53,22 @@ enum socketmap_reply{
 static int
 table_socketmap_connect(const char *s)
 {
-	struct sockaddr_un	sun;
+	struct sockaddr_un	lsun;
 
 	if ((sock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
 		log_warn("warn: socket");
 		goto err;
 	}
 
-	memset(&sun, 0, sizeof sun);
-	sun.sun_family = AF_UNIX;
-	if (strlcpy(sun.sun_path, s, sizeof(sun.sun_path)) >=
-	    sizeof(sun.sun_path)) {
+	memset(&lsun, 0, sizeof lsun);
+	lsun.sun_family = AF_UNIX;
+	if (strlcpy(lsun.sun_path, s, sizeof(lsun.sun_path)) >=
+	    sizeof(lsun.sun_path)) {
 		log_warnx("warn: socket path too long");
 		goto err;
 	}
 
-	if (connect(sock, (struct sockaddr *)&sun, sizeof(sun)) == -1) {
+	if (connect(sock, (struct sockaddr *)&lsun, sizeof(lsun)) == -1) {
 		log_warn("warn: connect");
 		goto err;
 	}
