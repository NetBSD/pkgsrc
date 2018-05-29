$NetBSD: patch-spmd_main.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Fix unused variable

--- spmd/main.c.orig	2008-07-11 18:35:46.000000000 -0400
+++ spmd/main.c	2018-05-28 19:26:45.583066490 -0400
@@ -378,11 +378,12 @@
 do_daemon(void)
 {
 	pid_t pid;
-	int en;
 
 	openlog("spmd", LOG_PID, LOG_DAEMON);
 	if (daemon(0, 0) < 0) { 
-		en = errno;
+#ifdef __linux__ /* glibc specific ? */
+		int en = errno;
+#endif
 		perror("daemon()"); 
 #ifdef __linux__ /* glibc specific ? */
 		if (en == 0) {
