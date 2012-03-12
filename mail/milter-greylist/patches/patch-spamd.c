$NetBSD: patch-spamd.c,v 1.1 2012/03/12 13:17:22 fhajny Exp $

Rename 'sun' to 's_un' to avoid a conflict on SunOS

--- spamd.c.orig	2010-06-22 02:13:41.000000000 +0000
+++ spamd.c
@@ -422,19 +422,19 @@ static int
 spamd_unix_socket(path)
 	char *path;
 {
-	struct sockaddr_un sun;
+	struct sockaddr_un s_un;
 	int sock;
 	
-	bzero(&sun, sizeof(sun));
-	sun.sun_family = AF_UNIX;
-	strncpy(sun.sun_path, path, sizeof(sun.sun_path) - 1);
+	bzero(&s_un, sizeof(s_un));
+	s_un.sun_family = AF_UNIX;
+	strncpy(s_un.sun_path, path, sizeof(s_un.sun_path) - 1);
 
 	if ((sock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
 		mg_log(LOG_ERR, "spamd socket failed: %s", strerror(errno));
 		return -1;
 	}
 
-	if (connect(sock, (struct sockaddr*) &sun, sizeof(sun))) {
+	if (connect(sock, (struct sockaddr*) &s_un, sizeof(s_un))) {
 		mg_log(LOG_ERR, "spamd connect failed: %s", strerror(errno));
 		return -1;
 	}
