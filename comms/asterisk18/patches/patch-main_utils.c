$NetBSD: patch-main_utils.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- main/utils.c.orig	2018-05-01 20:12:26.000000000 +0000
+++ main/utils.c
@@ -39,6 +39,10 @@
 #elif defined(HAVE_SYS_THR_H)
 #include <sys/thr.h>
 #endif
+#if defined(HAVE_GETIFADDRS)
+#include <ifaddrs.h>
+#include <net/if_dl.h>
+#endif
 
 #include "asterisk/network.h"
 #include "asterisk/ast_version.h"
@@ -204,7 +208,7 @@ struct hostent *ast_gethostbyname(const 
 	while (s && *s) {
 		if (*s == '.')
 			dots++;
-		else if (!isdigit(*s))
+		else if (!isdigit((unsigned char)*s))
 			break;
 		s++;
 	}
@@ -612,7 +616,7 @@ const char *ast_inet_ntoa(struct in_addr
 
 static int dev_urandom_fd = -1;
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__DragonFly__)
 #undef pthread_create /* For ast_pthread_create function only */
 #endif /* !__linux__ */
 
@@ -1820,13 +1824,13 @@ int ast_false(const char *s)
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
@@ -1986,7 +1990,7 @@ char *ast_to_camel_case_delim(const char
 
 	while (front) {
 		size = strlen(front);
-		*front = toupper(*front);
+		*front = toupper((unsigned char)*front);
 		ast_copy_string(buf, front, size + 1);
 		buf += size;
 		front = strtok_r(NULL, delim, &back);
