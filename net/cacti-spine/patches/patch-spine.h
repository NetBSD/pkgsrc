$NetBSD: patch-spine.h,v 1.1 2016/06/02 16:00:02 hauke Exp $

Despite the autoconf --sysconfdir, spine uses a hardcoded path to
look for its config file. Patch that for pkgsrc.

--- spine.h.orig	2016-05-08 18:57:41.000000000 +0000
+++ spine.h
@@ -136,7 +136,7 @@
 
 /* locations to search for the config file */
 #define CONFIG_PATHS 4
-#define CONFIG_PATH_1 ""
+#define CONFIG_PATH_1 "@PKG_SYSCONFDIR@/"
 #define CONFIG_PATH_2 "/etc/"
 #define CONFIG_PATH_3 "/etc/cacti/"
 #define CONFIG_PATH_4 "../etc/"
