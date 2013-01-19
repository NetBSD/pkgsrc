$NetBSD: patch-src_plugins_quota_quota-fs.h,v 1.1 2013/01/19 05:25:51 manu Exp $

Support NetBSD's libquota

--- src/plugins/quota/quota-fs.h.orig	2011-12-13 12:35:29.000000000 +0100
+++ src/plugins/quota/quota-fs.h	2013-01-18 20:10:34.000000000 +0100
@@ -5,8 +5,12 @@
 	defined (HAVE_STRUCT_DQBLK_CURSPACE)
 #  define HAVE_FS_QUOTA
 #endif
 
+#ifdef HAVE_QUOTA_OPEN
+#  include <quota.h> /* NetBSD with libquota */
+#endif
+
 #ifdef HAVE_SYS_QUOTA_H
 #  include <sys/quota.h> /* Linux, HP-UX */
 #elif defined(HAVE_SYS_FS_UFS_QUOTA_H)
 #  include <sys/fs/ufs_quota.h> /* Solaris */
@@ -36,5 +40,11 @@
 #else
 #  undef HAVE_FS_QUOTA
 #endif
 
+#ifdef HAVE_QUOTA_OPEN /* NetBSD with libquota */
+#  define FS_QUOTA_NETBSD
+#  define HAVE_FS_QUOTA
+#  undef FS_QUOTA_LINUX /* obtained because we also have <sys/quota.h> */
+#endif
+
 #endif
