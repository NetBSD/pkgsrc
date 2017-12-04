$NetBSD: patch-udp.h,v 1.1 2017/12/04 23:59:21 jmcneill Exp $

--- udp.h.orig	2012-01-26 11:02:46.000000000 +0000
+++ udp.h
@@ -1,11 +1,6 @@
 #ifndef udp_h
 #define udp_h
 
-
-#ifdef __MACH__
-typedef int socklen_t;
-#endif
-
 #include <errno.h>
 
 #ifdef WIN32
