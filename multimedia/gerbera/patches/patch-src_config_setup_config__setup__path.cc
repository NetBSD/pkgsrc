$NetBSD: patch-src_config_setup_config__setup__path.cc,v 1.1 2026/06/25 08:16:53 wiz Exp $

Fix build.
https://github.com/gerbera/gerbera/issues/3897

--- src/config/setup/config_setup_path.cc.orig	2026-06-25 07:58:51.173207423 +0000
+++ src/config/setup/config_setup_path.cc
@@ -60,7 +60,7 @@ bool ConfigPathSetup::checkExecutable(std::string& opt
 
     int err = 0;
     if (!isExecutable(tmpPath, &err)) {
-        log_warning("Error in configuration, file {} is not executable: {} for '{}'", optValue, std::strerror(err), cpath);
+        log_warning("Error in configuration, file {} is not executable: {} for '{}'", optValue, strerror(err), cpath);
         return !isSet(ConfigPathArguments::mustExist);
     }
     return true;
