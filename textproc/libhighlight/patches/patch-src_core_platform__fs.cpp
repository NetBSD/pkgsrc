$NetBSD: patch-src_core_platform__fs.cpp,v 1.5 2024/08/16 15:27:59 schmonz Exp $

Fix build on (at least) SmartOS.

--- src/core/platform_fs.cpp.orig	2024-08-11 13:05:37.000000000 +0000
+++ src/core/platform_fs.cpp
@@ -65,7 +65,7 @@ namespace Platform
 const char pathSeparator = '\\';
 
 #ifndef QT
-std::string getAppPath()
+::std::string getAppPath()
 {
     char pathAndName[MAX_PATH], path[MAX_PATH], drive[3];
     GetModuleFileName(NULL, pathAndName, MAX_PATH);
@@ -74,7 +74,7 @@ std::string getAppPath()
 }
 #endif
 
-std::string getHomePath()
+::std::string getHomePath()
 {
     return "";
 }
@@ -149,8 +149,8 @@ int isDarkTerminal() {
     return 1;
 }
 
-std::string getTempFilePath(){
-    std::string path("/tmp");
+::std::string getTempFilePath(){
+    ::std::string path("/tmp");
 
     char* tempOption=getenv("TEMP");
     if (tempOption) path=string(tempOption);
