$NetBSD: patch-main_utils.c,v 1.1.1.1 2012/01/15 18:36:21 jnemeth Exp $

--- main/utils.c.orig	2011-11-02 21:37:11.000000000 +0000
+++ main/utils.c
@@ -484,7 +484,7 @@ const char *ast_inet_ntoa(struct in_addr
 static int dev_urandom_fd;
 #endif
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__DragonFly__)
 #undef pthread_create /* For ast_pthread_create function only */
 #endif /* !__linux__ */
 
@@ -1392,13 +1392,13 @@ int ast_false(const char *s)
 static struct timeval tvfix(struct timeval a)
 {
 	if (a.tv_usec >= ONE_MILLION) {
-		ast_log(LOG_WARNING, "warning too large timestamp %ld.%ld\n",
-			(long)a.tv_sec, (long int) a.tv_usec);
+		ast_log(LOG_WARNING, "warning too large timestamp %jd.%ld\n",
+			(intmax_t)a.tv_sec, (long int) a.tv_usec);
 		a.tv_sec += a.tv_usec / ONE_MILLION;
 		a.tv_usec %= ONE_MILLION;
 	} else if (a.tv_usec < 0) {
-		ast_log(LOG_WARNING, "warning negative timestamp %ld.%ld\n",
-			(long)a.tv_sec, (long int) a.tv_usec);
+		ast_log(LOG_WARNING, "warning negative timestamp %jd.%ld\n",
+			(intmax_t)a.tv_sec, (long int) a.tv_usec);
 		a.tv_usec = 0;
 	}
 	return a;
