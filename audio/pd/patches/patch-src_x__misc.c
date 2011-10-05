$NetBSD: patch-src_x__misc.c,v 1.2 2011/10/05 20:02:48 wiz Exp $

Define missing symbol the same as on FreeBSD/Mac OS X.
https://sourceforge.net/tracker/?func=detail&aid=3411732&group_id=55736&atid=478072

--- src/x_misc.c.orig	2010-07-28 20:55:17.000000000 +0000
+++ src/x_misc.c
@@ -20,7 +20,7 @@
 #include <unistd.h>
 #endif /* _WIN32 */
 
-#if defined (__APPLE__) || defined (__FreeBSD__)
+#if defined (__APPLE__) || defined (__FreeBSD__) || defined(__NetBSD__)
 #define CLOCKHZ CLK_TCK
 #endif
 #if defined (__linux__) || defined (__CYGWIN__) || defined (ANDROID)
