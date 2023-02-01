$NetBSD: patch-src_include_gnunet_mysql_compat.h,v 1.1 2023/02/01 19:03:03 nikita Exp $

upstream commit ac40efdae723f850bfff62c0cddad130a37f425e
MYSQL: Use autoconf-based my_bool detection

NEWS: We now detect MySQL's strange, version-dependent my_bool type on configure.

--- src/include/gnunet_mysql_compat.h.orig	2023-02-01 19:25:58.608530686 +0100
+++ src/include/gnunet_mysql_compat.h	2023-02-01 19:27:33.129458021 +0100
@@ -41,16 +41,6 @@
 #endif
 #endif
 
-#ifndef LIBMARIADB
-#if MYSQL_VERSION_ID < 80000
-#define MYSQL_BOOL bool;
-#else
-#define MYSQL_BOOL my_bool; //MySQL < 8 wants this
-#endif
-#else
-#define MYSQL_BOOL my_bool //MariaDB still uses my_bool
-#endif
-
 #if 0                           /* keep Emacsens' auto-indent happy */
 {
 #endif
