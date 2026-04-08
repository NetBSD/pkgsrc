$NetBSD: patch-src_cfg.c,v 1.1 2026/04/08 16:08:48 sborrill Exp $

Avoid a broken config file path after converting /etc to PKG_SYSCONFDIR

--- src/cfg.c.orig	2026-04-08 16:25:51.959370085 +0100
+++ src/cfg.c	2026-04-08 16:26:06.796945373 +0100
@@ -484,8 +484,6 @@
 			strncpy_nt(cfg.cfgfile, buffer, 512);
 		} else if ((*fd = fopen("/etc/vnstat.conf", "r")) != NULL) {
 			snprintf(cfg.cfgfile, 512, "/etc/vnstat.conf");
-		} else if ((*fd = fopen("/usr/local/etc/vnstat.conf", "r")) != NULL) {
-			snprintf(cfg.cfgfile, 512, "/usr/local/etc/vnstat.conf");
 		} else {
 			if (debug)
 				printf("Config file: none\n");
