$NetBSD: patch-alc_alconfig.cpp,v 1.4 2025/01/30 11:08:40 adam Exp $

Allow the Makefile to specify the default config file path.

--- alc/alconfig.cpp.orig	2025-01-11 07:17:23.000000000 +0000
+++ alc/alconfig.cpp
@@ -381,7 +381,7 @@ void ReadALConfig()
 
 void ReadALConfig()
 {
-    fs::path path{"/etc/openal/alsoft.conf"};
+    fs::path path{SYS_CONF_DIR "/alsoft.conf"};
 
     TRACE("Loading config {}...", al::u8_as_char(path.u8string()));
     if(fs::ifstream f{path}; f.is_open())
