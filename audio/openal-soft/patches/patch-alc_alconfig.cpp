$NetBSD: patch-alc_alconfig.cpp,v 1.5 2025/12/22 15:17:58 ryoon Exp $

Allow the Makefile to specify the default config file path.

--- alc/alconfig.cpp.orig	2025-12-22 09:17:45.000000000 +0000
+++ alc/alconfig.cpp
@@ -426,7 +426,7 @@ void ReadALConfig()
 
 void ReadALConfig()
 {
-    auto path = fs::path{"/etc/openal/alsoft.conf"};
+    auto path = fs::path{SYS_CONF_DIR "/alsoft.conf"};
 
     TRACE("Loading config {}...", al::u8_as_char(path.u8string()));
     if(auto f = fs::ifstream{path}; f.is_open())
