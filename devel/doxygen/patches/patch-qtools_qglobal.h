$NetBSD: patch-qtools_qglobal.h,v 1.1 2019/10/17 20:35:58 adam Exp $

Add DragonFly support.

--- qtools/qglobal.h.orig	2019-03-16 19:19:44.000000000 +0000
+++ qtools/qglobal.h
@@ -102,7 +102,7 @@
 #define _OS_RELIANTUNIX_
 #elif defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)
 #define _OS_LINUX_
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #define _OS_FREEBSD_
 #elif defined(__NetBSD__)
 #define _OS_NETBSD_
