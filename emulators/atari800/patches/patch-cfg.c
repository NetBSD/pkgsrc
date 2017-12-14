$NetBSD: patch-cfg.c,v 1.1 2017/12/14 22:12:19 adam Exp $

Provide PkgSrc path for the configuration file.

--- cfg.c.orig	2014-04-05 19:40:14.000000000 +0000
+++ cfg.c
@@ -68,7 +68,7 @@ int CFG_save_on_exit = FALSE;
 #endif
 
 #ifndef SYSTEM_WIDE_CFG_FILE
-#define SYSTEM_WIDE_CFG_FILE "/etc/atari800.cfg"
+#define SYSTEM_WIDE_CFG_FILE PREFIX "/share/atari800/atari800.cfg"
 #endif
 
 static char rtconfig_filename[FILENAME_MAX];
