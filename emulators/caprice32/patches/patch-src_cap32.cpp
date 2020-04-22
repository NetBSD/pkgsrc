$NetBSD: patch-src_cap32.cpp,v 1.2 2020/04/22 08:13:40 nia Exp $

Fix paths.

--- src/cap32.cpp.orig	2020-03-14 14:36:08.000000000 +0000
+++ src/cap32.cpp
@@ -1577,7 +1577,7 @@ std::string getConfigurationFilename(boo
     { getenv("XDG_CONFIG_HOME"), "/cap32.cfg" },
     { getenv("HOME"), "/.config/cap32.cfg" },
     { getenv("HOME"), "/.cap32.cfg" },
-    { PATH_OK, "/etc/cap32.cfg"}
+    { PATH_OK, "@PKG_SYSCONFDIR@/cap32.cfg"}
   };
 
   for(const auto& p: configPaths){
