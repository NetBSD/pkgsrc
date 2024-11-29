$NetBSD: patch-alc_alconfig.cpp,v 1.3 2024/11/29 03:47:45 ryoon Exp $

Allow the Makefile to specify the default config file path.

--- alc/alconfig.cpp.orig	2024-11-28 03:21:16.000000000 +0000
+++ alc/alconfig.cpp
@@ -384,7 +384,7 @@ void ReadALConfig()
 void ReadALConfig()
 {
     namespace fs = std::filesystem;
-    fs::path path{"/etc/openal/alsoft.conf"};
+    fs::path path{SYS_CONF_DIR "/alsoft.conf"};
 
     TRACE("Loading config %s...\n", reinterpret_cast<const char*>(path.u8string().c_str()));
     if(std::ifstream f{path}; f.is_open())
