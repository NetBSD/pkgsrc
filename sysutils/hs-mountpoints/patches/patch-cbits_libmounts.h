$NetBSD: patch-cbits_libmounts.h,v 1.1 2023/10/31 18:48:34 pho Exp $

Support NetBSD. The upstream doesn't seem to be accepting pull requests.

--- cbits/libmounts.h.orig	2016-03-15 17:20:47.000000000 +0000
+++ cbits/libmounts.h
@@ -2,11 +2,15 @@
 #if defined __ANDROID__
 # define UNKNOWN
 #else
-#if defined (__FreeBSD__) || defined (__APPLE__)
+#if defined (__FreeBSD__) || defined (__NetBSD__) || defined (__APPLE__)
 # include <sys/param.h>
 # include <sys/ucred.h>
 # include <sys/mount.h>
 # define GETMNTINFO
+# if defined(__NetBSD__)
+/* NetBSD uses struct statvfs instead of struct statfs. */
+#   define statfs statvfs
+# endif
 #else
 #if defined (__linux__) || defined (__FreeBSD_kernel__)
 /* Linux or Debian kFreeBSD */
