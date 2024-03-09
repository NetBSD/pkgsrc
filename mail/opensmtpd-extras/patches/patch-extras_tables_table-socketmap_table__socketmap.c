$NetBSD: patch-extras_tables_table-socketmap_table__socketmap.c,v 1.1 2024/03/09 23:55:46 vins Exp $

Rename local variables to avoid name clash on SmartOS

--- extras/tables/table-socketmap/table_socketmap.c.orig	2024-03-09 22:58:23.569776538 +0000
+++ extras/tables/table-socketmap/table_socketmap.c
@@ -48,22 +48,22 @@ enum socketmap_reply{
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
