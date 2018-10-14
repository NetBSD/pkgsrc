$NetBSD: patch-src_core_platform__fs.cpp,v 1.2 2018/10/14 12:17:50 schmonz Exp $

Fix build on (at least) SmartOS.

--- src/core/platform_fs.cpp.orig	2018-10-13 19:26:45.000000000 +0000
+++ src/core/platform_fs.cpp
@@ -79,13 +79,13 @@ int isColorEscCapable() {
 
 const char pathSeparator = '/';
 
-std::string getAppPath()
+::std::string getAppPath()
 {
     return "";
 }
 
 
-std::string getHomePath()
+::std::string getHomePath()
 {
     struct passwd *pw = getpwuid(getuid());
     return string(pw->pw_dir);
