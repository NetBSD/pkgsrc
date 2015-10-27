$NetBSD: patch-backend_kodakaio.c,v 1.3 2015/10/27 11:29:35 wiz Exp $

DragonFly build fix.
https://alioth.debian.org/tracker/index.php?func=detail&aid=315207&group_id=30186&atid=410366

--- backend/kodakaio.c.orig	2013-08-25 21:22:58.000000000 +0000
+++ backend/kodakaio.c
@@ -181,6 +181,7 @@ normal levels. This system is a plan rat
 #include <math.h>
 #include <poll.h>
 #include <time.h>
+#include <sys/socket.h>
 
 #if WITH_AVAHI
 /* used for auto detecting network printers  */
