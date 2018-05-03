$NetBSD: patch-src_core_platform__fs.cpp,v 1.1 2018/05/03 13:13:51 schmonz Exp $

Fix build on (at least) SmartOS.

--- src/core/platform_fs.cpp.orig	2018-01-20 20:42:17.000000000 +0000
+++ src/core/platform_fs.cpp
@@ -72,13 +72,13 @@ std::string getHomePath()
 #include <pwd.h>
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
