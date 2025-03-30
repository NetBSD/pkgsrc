$NetBSD: patch-alc_alconfig.cpp,v 1.1 2025/03/30 09:32:57 nia Exp $

Allow the Makefile to specify the default config file path.

--- alc/alconfig.cpp.orig	2025-03-30 09:19:12.176855304 +0000
+++ alc/alconfig.cpp
@@ -364,7 +364,7 @@ void ReadALConfig()
 
 void ReadALConfig()
 {
-    const char *str{"/etc/openal/alsoft.conf"};
+    const char *str{SYS_CONF_DIR"/alsoft.conf"};
 
     TRACE("Loading config %s...\n", str);
     al::ifstream f{str};
@@ -372,7 +372,7 @@ void ReadALConfig()
         LoadConfigFromFile(f);
     f.close();
 
-    std::string confpaths{al::getenv("XDG_CONFIG_DIRS").value_or("/etc/xdg")};
+    std::string confpaths{al::getenv("XDG_CONFIG_DIRS").value_or(SYS_CONF_DIR"/xdg")};
     /* Go through the list in reverse, since "the order of base directories
      * denotes their importance; the first directory listed is the most
      * important". Ergo, we need to load the settings from the later dirs
