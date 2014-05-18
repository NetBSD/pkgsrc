$NetBSD: patch-fscadm_fscadm.c,v 1.1 2014/05/18 21:24:04 joerg Exp $

--- fscadm/fscadm.c.orig	2014-05-17 02:44:47.000000000 +0000
+++ fscadm/fscadm.c
@@ -157,7 +157,9 @@ version(void)
 int
 daemonconnect(char *task)
 {
-	int s, len, nbytes, retcode = 0;
+	int s, retcode = 0;
+	size_t len;
+	ssize_t nbytes;
 	struct sockaddr_un remote;
 	char recdata[LINE_MAX];
 
@@ -168,7 +170,7 @@ daemonconnect(char *task)
 	strncpy(remote.sun_path, socketname ? socketname : SOCK_PATH,
 			sizeof remote.sun_path);
 	len = strlen(remote.sun_path) + sizeof(remote.sun_family) + 1;
-	if (connect(s, (struct sockaddr *)&remote, len) == -1)
+	if (connect(s, (struct sockaddr *)&remote, (socklen_t)len) == -1)
 		err(EX_OSERR, "connect");
 
 	if (send(s, task, strlen(task), 0) == -1)
@@ -183,7 +185,7 @@ daemonconnect(char *task)
 
 	if (nbytes < 0) {
 		warn("recv");
-		retcode = nbytes;
+		retcode = -1;
 	}
 
 	close(s);
