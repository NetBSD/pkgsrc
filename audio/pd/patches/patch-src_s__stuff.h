$NetBSD: patch-src_s__stuff.h,v 1.3 2012/02/15 22:36:39 hans Exp $

Use OSS on NetBSD.
https://sourceforge.net/tracker/?func=detail&aid=3411732&group_id=55736&atid=478072

--- src/s_stuff.h.orig	2011-03-13 00:19:29.000000000 +0000
+++ src/s_stuff.h
@@ -204,7 +204,7 @@ void sys_setalarm(int microsec);
 #define API_DEFAULT API_DUMMY
 #define API_DEFSTRING "dummy audio"
 #else
-#if defined(__linux__) || defined(__FreeBSD_kernel__)
+#if defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__sun)
 # define API_DEFAULT API_OSS
 # define API_DEFSTRING "OSS"
 #endif
