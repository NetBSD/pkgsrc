$NetBSD: patch-backend_kodakaio.c,v 1.2 2015/08/16 20:24:23 leot Exp $

--- backend/kodakaio.c.orig	2013-08-25 21:22:58.000000000 +0000
+++ backend/kodakaio.c
@@ -181,6 +181,7 @@ normal levels. This system is a plan rat
 #include <math.h>
 #include <poll.h>
 #include <time.h>
+#include <sys/socket.h>
 
 #if WITH_AVAHI
 /* used for auto detecting network printers  */
