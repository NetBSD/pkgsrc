$NetBSD: patch-zthread_include_zthread_Config.h,v 1.1 2012/08/07 16:44:50 marino Exp $

--- zthread/include/zthread/Config.h.orig	2008-03-01 02:08:48.000000000 +0000
+++ zthread/include/zthread/Config.h
@@ -111,6 +111,7 @@
 // Check for well known platforms
 #elif defined(__linux__) || \
       defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || \
+      defined(__DragonFly__) || \
       defined(__hpux) || \
       defined(__sgi) || \
       defined(__sun)
