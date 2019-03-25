$NetBSD: patch-Alc_alconfig.c,v 1.1 2019/03/25 14:20:37 wiz Exp $

Allow the Makefile to specify the default config file path.

--- Alc/alconfig.c.orig	2018-10-11 22:05:31.000000000 +0000
+++ Alc/alconfig.c
@@ -428,7 +428,7 @@ void ReadALConfig(void)
     const char *str;
     FILE *f;
 
-    str = "/etc/openal/alsoft.conf";
+    str = SYS_CONF_DIR "/alsoft.conf";
 
     TRACE("Loading config %s...\n", str);
     f = al_fopen(str, "r");
