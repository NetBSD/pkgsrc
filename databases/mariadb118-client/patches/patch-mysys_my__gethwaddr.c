$NetBSD: patch-mysys_my__gethwaddr.c,v 1.2 2025/10/27 20:56:37 nia Exp $

SunOS doesn't support hwaddr.

--- mysys/my_gethwaddr.c.orig	2022-09-13 06:00:23.000000000 +0000
+++ mysys/my_gethwaddr.c
@@ -74,7 +74,7 @@ err:
   return res;
 }
 
-#elif defined(_AIX) || defined(__linux__) || defined(__sun)
+#elif defined(_AIX) || defined(__linux__)
 #include <net/if.h>
 #include <sys/ioctl.h>
 #include <net/if_arp.h>
