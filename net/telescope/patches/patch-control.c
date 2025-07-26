$NetBSD: patch-control.c,v 1.1 2025/07/26 21:41:39 vins Exp $

Rename local variables to avoid name clash on SunOS.

--- control.c.orig	2025-07-26 20:42:09.132038342 +0000
+++ control.c
@@ -59,7 +59,7 @@ TAILQ_HEAD(ctl_conns, ctl_conn) ctl_conn
 int
 control_init(char *path)
 {
-	struct sockaddr_un	 sun;
+	struct sockaddr_un	 lsun;
 	int			 fd;
 	mode_t			 old_umask;
 
@@ -73,9 +73,9 @@ control_init(char *path)
 		return (-1);
 	}
 
-	memset(&sun, 0, sizeof(sun));
-	sun.sun_family = AF_UNIX;
-	strlcpy(sun.sun_path, path, sizeof(sun.sun_path));
+	memset(&lsun, 0, sizeof(lsun));
+	lsun.sun_family = AF_UNIX;
+	strlcpy(lsun.sun_path, path, sizeof(lsun.sun_path));
 
 	if (unlink(path) == -1)
 		if (errno != ENOENT) {
@@ -85,7 +85,7 @@ control_init(char *path)
 		}
 
 	old_umask = umask(S_IXUSR|S_IXGRP|S_IWOTH|S_IROTH|S_IXOTH);
-	if (bind(fd, (struct sockaddr *)&sun, sizeof(sun)) == -1) {
+	if (bind(fd, (struct sockaddr *)&lsun, sizeof(lsun)) == -1) {
 		warn("%s: bind: %s", __func__, path);
 		close(fd);
 		umask(old_umask);
@@ -121,15 +121,15 @@ control_accept(int listenfd, int event,
 {
 	int			 connfd;
 	socklen_t		 len;
-	struct sockaddr_un	 sun;
+	struct sockaddr_un	 lsun;
 	struct ctl_conn		*c;
 
 	ev_add(control_state.fd, EV_READ, control_accept, NULL);
 	if ((event & EV_TIMEOUT))
 		return;
 
-	len = sizeof(sun);
-	if ((connfd = accept(listenfd, (struct sockaddr *)&sun, &len)) == -1) {
+	len = sizeof(lsun);
+	if ((connfd = accept(listenfd, (struct sockaddr *)&lsun, &len)) == -1) {
 		/*
 		 * Pause accept if we are out of file descriptors, or
 		 * ev will haunt us here too.
