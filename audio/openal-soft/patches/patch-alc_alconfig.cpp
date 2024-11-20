$NetBSD: patch-alc_alconfig.cpp,v 1.2 2024/11/20 09:33:00 adam Exp $

Allow the Makefile to specify the default config file path.

--- alc/alconfig.cpp.orig	2024-11-16 12:20:51.000000000 +0000
+++ alc/alconfig.cpp
@@ -383,7 +383,7 @@ void ReadALConfig()
 void ReadALConfig()
 {
     namespace fs = std::filesystem;
-    fs::path path{"/etc/openal/alsoft.conf"};
+    fs::path path{SYS_CONF_DIR "/alsoft.conf"};
 
     TRACE("Loading config %s...\n", path.u8string().c_str());
     if(std::ifstream f{path}; f.is_open())
