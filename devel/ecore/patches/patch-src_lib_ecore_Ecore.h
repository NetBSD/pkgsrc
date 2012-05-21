$NetBSD: patch-src_lib_ecore_Ecore.h,v 1.1 2012/05/21 06:21:41 marino Exp $

--- src/lib/ecore/Ecore.h.orig	2012-05-21 05:28:16.000000000 +0000
+++ src/lib/ecore/Ecore.h
@@ -295,7 +295,8 @@
 
 #ifdef _WIN32
 # include <winsock2.h>
-#elif (defined (__FreeBSD__) && (__FreeBSD_version >= 420001)) || defined (__OpenBSD__)
+#elif (defined (__FreeBSD__) && (__FreeBSD_version >= 420001)) \
+    || defined (__OpenBSD__) || defined(__DragonFly__)
 # include <sys/select.h>
 # include <signal.h>
 #else
