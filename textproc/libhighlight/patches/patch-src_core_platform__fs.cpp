$NetBSD: patch-src_core_platform__fs.cpp,v 1.3 2019/08/28 14:38:42 schmonz Exp $

Fix build on (at least) SmartOS.

--- src/core/platform_fs.cpp.orig	2019-07-31 21:48:56.000000000 +0000
+++ src/core/platform_fs.cpp
@@ -91,13 +91,13 @@ std::string getTempFilePath(){
 
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
@@ -127,8 +127,8 @@ int isColorEscCapable() {
     return 0;
 }
 
-std::string getTempFilePath(){
-    std::string path("/tmp");
+::std::string getTempFilePath(){
+    ::std::string path("/tmp");
     
     char* tempOption=getenv("TEMP");
     if (tempOption) path=string(tempOption);
