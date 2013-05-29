$NetBSD: patch-src_x__misc.c,v 1.4 2013/05/29 11:26:12 wiz Exp $

Define missing symbol the same as on FreeBSD/Mac OS X for NetBSD.
https://sourceforge.net/tracker/?func=detail&aid=3411732&group_id=55736&atid=478072

Define missing symbol the same as on FreeBSD/Mac OS X for OpenBSD.

Define missing symbol the same as on FreeBSD/Mac OS X for Solaris.

--- src/x_misc.c.orig	2010-07-28 20:55:17.000000000 +0000
+++ src/x_misc.c
@@ -20,7 +20,7 @@
 #include <unistd.h>
 #endif /* _WIN32 */
 
-#if defined (__APPLE__) || defined (__FreeBSD__)
+#if defined (__APPLE__) || defined (__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__sun)
 #define CLOCKHZ CLK_TCK
 #endif
 #if defined (__linux__) || defined (__CYGWIN__) || defined (ANDROID)
