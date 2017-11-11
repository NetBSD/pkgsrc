$NetBSD: patch-internal_easylogging++.h,v 1.2 2017/11/11 03:18:16 gdt Exp $

NetBSD support, it's a unixy OS.

--- internal/easylogging++.h.orig	2017-07-25 18:26:45.000000000 +0000
+++ internal/easylogging++.h
@@ -98,13 +98,18 @@
 #else
 #  define ELPP_OS_FREEBSD 0
 #endif
+#if (defined(__NetBSD__))
+#   define ELPP_OS_NETBSD 1
+#else
+#   define ELPP_OS_NETBSD 0
+#endif
 #if (defined(__sun))
 #  define ELPP_OS_SOLARIS 1
 #else
 #  define ELPP_OS_SOLARIS 0
 #endif
 // Unix
-#if ((ELPP_OS_LINUX || ELPP_OS_MAC || ELPP_OS_FREEBSD || ELPP_OS_SOLARIS) && (!ELPP_OS_WINDOWS))
+#if ((ELPP_OS_LINUX || ELPP_OS_MAC || ELPP_OS_FREEBSD || ELPP_OS_NETBSD || ELPP_OS_SOLARIS) && (!ELPP_OS_WINDOWS))
 #  define ELPP_OS_UNIX 1
 #else
 #  define ELPP_OS_UNIX 0
