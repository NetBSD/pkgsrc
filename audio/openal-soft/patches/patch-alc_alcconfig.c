$NetBSD: patch-alc_alcconfig.c,v 1.1 2016/02/08 01:53:48 markd Exp $

Allow the Makefile to specify the default config file path.

--- Alc/alcConfig.c.orig	2016-01-29 11:04:27.000000000 +0100
+++ Alc/alcConfig.c	2016-01-29 11:04:41.000000000 +0100
@@ -353,7 +353,7 @@
     const char *str;
     FILE *f;
 
-    str = "/etc/openal/alsoft.conf";
+    str = SYS_CONF_DIR "/alsoft.conf";
 
     TRACE("Loading config %s...\n", str);
     f = al_fopen(str, "r");
