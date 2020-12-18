$NetBSD: patch-src_core_platform__fs.cpp,v 1.4 2020/12/18 18:45:08 schmonz Exp $

Fix build on (at least) SmartOS.

--- src/core/platform_fs.cpp.orig	2020-11-13 20:00:38.000000000 +0000
+++ src/core/platform_fs.cpp
@@ -95,12 +95,12 @@ std::string getTempFilePath(){
 
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
     return pw != NULL ? string(pw->pw_dir) : "";
@@ -140,8 +140,8 @@ int isDarkTerminal() {
     return 1;
 }
 
-std::string getTempFilePath(){
-    std::string path("/tmp");
+::std::string getTempFilePath(){
+    ::std::string path("/tmp");
 
     char* tempOption=getenv("TEMP");
     if (tempOption) path=string(tempOption);
