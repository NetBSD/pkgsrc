$NetBSD: patch-main_utils.c,v 1.2 2020/03/22 23:09:24 tnn Exp $

--- main/utils.c.orig	2019-12-23 16:43:56.000000000 +0000
+++ main/utils.c
@@ -39,6 +39,12 @@
 #elif defined(HAVE_SYS_THR_H)
 #include <sys/thr.h>
 #endif
+#if defined(HAVE_GETIFADDRS)
+#include <ifaddrs.h>
+#if !defined(__linux__)
+#include <net/if_dl.h>
+#endif
+#endif
 
 #include "asterisk/network.h"
 #include "asterisk/ast_version.h"
@@ -612,7 +618,7 @@ const char *ast_inet_ntoa(struct in_addr
 
 static int dev_urandom_fd = -1;
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__DragonFly__)
 #undef pthread_create /* For ast_pthread_create function only */
 #endif /* !__linux__ */
 
