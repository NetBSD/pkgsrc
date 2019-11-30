$NetBSD: patch-alc_alconfig.cpp,v 1.1 2019/11/30 13:40:29 nia Exp $

Allow the Makefile to specify the default config file path.

--- alc/alconfig.cpp.orig	2019-11-28 08:45:08.000000000 +0000
+++ alc/alconfig.cpp
@@ -325,7 +325,7 @@ void ReadALConfig()
 
 void ReadALConfig()
 {
-    const char *str{"/etc/openal/alsoft.conf"};
+    const char *str{SYS_CONF_DIR "/alsoft.conf"};
 
     TRACE("Loading config %s...\n", str);
     al::ifstream f{str};
