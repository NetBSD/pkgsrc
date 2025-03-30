$NetBSD: patch-Alc_alconfig.c,v 1.1 2025/03/30 09:32:07 nia Exp $

Allow the Makefile to specify the default config file path.

--- Alc/alconfig.c.orig	2025-03-24 15:38:04.295146953 +0000
+++ Alc/alconfig.c
@@ -428,7 +428,7 @@ void ReadALConfig(void)
     const char *str;
     FILE *f;
 
-    str = "/etc/openal/alsoft.conf";
+    str = SYS_CONF_DIR "/openal/alsoft.conf";
 
     TRACE("Loading config %s...\n", str);
     f = al_fopen(str, "r");
@@ -439,7 +439,7 @@ void ReadALConfig(void)
     }
 
     if(!(str=getenv("XDG_CONFIG_DIRS")) || str[0] == 0)
-        str = "/etc/xdg";
+        str = SYS_CONF_DIR "/xdg";
     alstr_copy_cstr(&confpaths, str);
     /* Go through the list in reverse, since "the order of base directories
      * denotes their importance; the first directory listed is the most
