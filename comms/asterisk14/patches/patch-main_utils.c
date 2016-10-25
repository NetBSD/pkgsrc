$NetBSD: patch-main_utils.c,v 1.1.1.1 2016/10/25 08:17:05 jnemeth Exp $

--- main/utils.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ main/utils.c
@@ -41,6 +41,10 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 #elif defined(HAVE_SYS_THR_H)
 #include <sys/thr.h>
 #endif
+#if defined(HAVE_GETIFADDRS)
+#include <ifaddrs.h>
+#include <net/if_dl.h>
+#endif
 
 #include "asterisk/network.h"
 #include "asterisk/ast_version.h"
@@ -618,7 +622,7 @@ const char *ast_inet_ntoa(struct in_addr
 
 static int dev_urandom_fd = -1;
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__DragonFly__)
 #undef pthread_create /* For ast_pthread_create function only */
 #endif /* !__linux__ */
 
@@ -1846,13 +1850,13 @@ int ast_false(const char *s)
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
