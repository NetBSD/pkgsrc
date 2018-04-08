$NetBSD: patch-src_core_platform__fs.cpp,v 1.1 2018/04/08 19:40:29 schmonz Exp $

Fix build on (at least) SmartOS.

--- src/core/platform_fs.cpp.orig	2013-09-24 20:24:04.000000000 +0000
+++ src/core/platform_fs.cpp
@@ -71,13 +71,13 @@ namespace Platform
 #include <pwd.h>
 	const char pathSeparator = '/';
 
-	std::string getAppPath()
+	::std::string getAppPath()
 	{
 		return "";
 	}
 	
 	
-	std::string getHomePath()
+	::std::string getHomePath()
 	{
 	  struct passwd *pw = getpwuid(getuid());
 	  return string(pw->pw_dir);
