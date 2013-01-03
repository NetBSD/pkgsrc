$NetBSD: patch-spamd.c,v 1.2 2013/01/03 09:50:44 tron Exp $

Rename 'sun' to 's_un' to avoid a conflict on SunOS
and include <strings.h> if present
--- spamd.c.orig	2012-02-24 02:25:46.000000000 +0000
+++ spamd.c
@@ -44,6 +44,9 @@ __RCSID("$Id: spamd.c,v 1.22 2012/02/24
 #include <stdlib.h>
 #include <errno.h>
 #include <string.h>
+#ifdef HAVE_STRINGS_H
+#include <strings.h>            /* bzero, ... */
+#endif
 #include <unistd.h>
 #include <netdb.h>
 #include <sys/types.h>
@@ -436,12 +439,12 @@ static int
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
@@ -450,7 +453,7 @@ spamd_unix_socket(path)
 
 	SET_CLOEXEC(sock);
 
-	if (connect(sock, (struct sockaddr*) &sun, sizeof(sun))) {
+	if (connect(sock, (struct sockaddr*) &s_un, sizeof(s_un))) {
 		mg_log(LOG_ERR, "spamd connect failed: %s", strerror(errno));
 		return -1;
 	}
