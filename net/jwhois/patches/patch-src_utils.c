$NetBSD: patch-src_utils.c,v 1.2 2017/02/14 21:25:20 joerg Exp $

--- src/utils.c.orig	2007-06-26 07:00:20.000000000 +0000
+++ src/utils.c
@@ -38,6 +38,7 @@
 # include <netdb.h>
 #endif
 
+#include <sys/time.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
@@ -288,7 +289,7 @@ make_connect(const char *host, int port)
 
       retlen = sizeof(retval);
       error = getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &retval, &retlen);
-      if (error < 0 || retval)
+      if (error < 0 || !retval)
 	{
 	  break;
 	}
