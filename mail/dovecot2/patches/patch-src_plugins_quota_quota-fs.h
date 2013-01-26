$NetBSD: patch-src_plugins_quota_quota-fs.h,v 1.2 2013/01/26 19:38:54 bouyer Exp $

Support NetBSD's libquota

--- src/plugins/quota/quota-fs.h.orig	2011-12-13 12:35:29.000000000 +0100
+++ src/plugins/quota/quota-fs.h	2013-01-26 19:49:14.000000000 +0100
@@ -37,4 +37,12 @@
 #  undef HAVE_FS_QUOTA
 #endif
 
+#ifdef HAVE_QUOTA_OPEN /* NetBSD with libquota */
+#  define FS_QUOTA_NETBSD
+#  define HAVE_FS_QUOTA
+#  undef FS_QUOTA_LINUX /* obtained because we also have <sys/quota.h> */
+   /* absolute path to avoid confusion with ./quota.h */
+#  include "/usr/include/quota.h" /* absolute path to avoid confusion with ./quota.h */
+#endif
+
 #endif
