$NetBSD: patch-src_plugins_quota_quota-fs.h,v 1.4 2013/08/05 23:12:42 bouyer Exp $

fix support for NetBSD's libquota

--- src/plugins/quota/quota-fs.h.orig	2013-08-06 00:53:34.000000000 +0200
+++ src/plugins/quota/quota-fs.h	2013-08-06 00:54:29.000000000 +0200
@@ -7,7 +7,8 @@
 #endif
 
 #ifdef HAVE_QUOTA_OPEN
-#  include <quota.h> /* NetBSD with libquota */
+/* absolute path to avoid confusion with ./quota.h */
+#  include "/usr/include/quota.h" /* NetBSD with libquota */
 #endif
 
 #ifdef HAVE_SYS_QUOTA_H
