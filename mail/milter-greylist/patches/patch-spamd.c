$NetBSD: patch-spamd.c,v 1.4 2013/01/11 13:23:17 tron Exp $

Fix build under Solaris 11.

--- spamd.c.orig	2013-01-08 14:30:01.000000000 +0000
+++ spamd.c	2013-01-11 13:07:04.000000000 +0000
@@ -55,7 +55,11 @@
 #include "spf.h"
 #include "acl.h"
 #include "conf.h"
+#ifdef HAVE_OLD_QUEUE_H
 #include "queue.h"
+#else 
+#include <sys/queue.h>
+#endif
 #include "milter-greylist.h"
 
 #include "spamd.h"
@@ -439,7 +443,7 @@
 	struct sockaddr_un s_un;
 	int sock;
 	
-	bzero(&s_un, sizeof(s_un));
+	(void)memset(&s_un, 0, sizeof(s_un));
 	s_un.sun_family = AF_UNIX;
 	strncpy(s_un.sun_path, path, sizeof(s_un.sun_path) - 1);
 
@@ -468,7 +472,7 @@
 	int e;
 	int sock = -1;
 
-	bzero(&hints, sizeof(hints));
+	(void)memset(&hints, 0, sizeof(hints));
 	hints.ai_socktype = SOCK_STREAM;
 #ifdef AI_ADDRCONFIG
 	hints.ai_flags = AI_ADDRCONFIG;
