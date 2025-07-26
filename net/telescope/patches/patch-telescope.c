$NetBSD: patch-telescope.c,v 1.1 2025/07/26 21:41:39 vins Exp $

Rename local variables to avoid name clash on SunOS.

--- telescope.c.orig	2025-07-26 21:02:31.302028423 +0000
+++ telescope.c
@@ -1034,18 +1034,18 @@ start_child(enum telescope_process p, co
 static void
 send_url(const char *url)
 {
-	struct sockaddr_un	 sun;
+	struct sockaddr_un	 lsun;
 	struct imsgbuf		 ibuf;
 	int			 ctl_sock;
 
 	if ((ctl_sock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)
 		err(1, "socket");
 
-	memset(&sun, 0, sizeof(sun));
-	sun.sun_family = AF_UNIX;
-	strlcpy(sun.sun_path, ctlsock_path, sizeof(sun.sun_path));
+	memset(&lsun, 0, sizeof(lsun));
+	lsun.sun_family = AF_UNIX;
+	strlcpy(lsun.sun_path, ctlsock_path, sizeof(lsun.sun_path));
 
-	if (connect(ctl_sock, (struct sockaddr *)&sun, sizeof(sun)) == -1)
+	if (connect(ctl_sock, (struct sockaddr *)&lsun, sizeof(lsun)) == -1)
 		err(1, "connect: %s", ctlsock_path);
 
 	if (imsgbuf_init(&ibuf, ctl_sock) == -1)
