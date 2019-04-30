$NetBSD: patch-spine.h,v 1.2 2019/04/30 09:22:10 hauke Exp $

Despite the autoconf --sysconfdir, spine uses a hardcoded path to
look for its config file. Patch that for pkgsrc.

While here, patch in the net/cacti logfile path.

--- spine.h.orig	2019-02-24 14:53:23.000000000 +0000
+++ spine.h
@@ -145,7 +145,7 @@
 
 /* locations to search for the config file */
 #define CONFIG_PATHS 4
-#define CONFIG_PATH_1 ""
+#define CONFIG_PATH_1 "@PKG_SYSCONFDIR@/"
 #define CONFIG_PATH_2 "/etc/"
 #define CONFIG_PATH_3 "/etc/cacti/"
 #define CONFIG_PATH_4 "../etc/"
@@ -159,7 +159,7 @@
 #define DEFAULT_DB_PASS "cactiuser"
 #define DEFAULT_DB_PORT 3306
 #define DEFAULT_DB_PREG 0
-#define DEFAULT_LOGFILE "/var/www/html/cacti/log/cacti.log"
+#define DEFAULT_LOGFILE "@CACTI_LOGDIR@/cacti.log"
 #define DEFAULT_TIMEOUT 294000000
 
 /* threads constants */
