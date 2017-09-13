$NetBSD: patch-alc_alcconfig.c,v 1.2 2017/09/13 08:08:22 wiz Exp $

Allow the Makefile to specify the default config file path.

--- Alc/alcConfig.c.orig	2017-07-30 05:09:21.000000000 +0000
+++ Alc/alcConfig.c
@@ -424,7 +424,7 @@ void ReadALConfig(void)
     al_string ppath;
     FILE *f;
 
-    str = "/etc/openal/alsoft.conf";
+    str = SYS_CONF_DIR "/alsoft.conf";
 
     TRACE("Loading config %s...\n", str);
     f = al_fopen(str, "r");
