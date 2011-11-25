$NetBSD: patch-Source_util.cpp,v 1.1 2011/11/25 21:49:17 joerg Exp $

--- Source/util.cpp.orig	2011-11-25 20:21:46.000000000 +0000
+++ Source/util.cpp
@@ -595,7 +595,7 @@ string get_full_path(const string &path)
 #ifdef PATH_MAX
   static char buffer[PATH_MAX];
 #else//PATH_MAX
-  int path_max = pathconf(path, _PC_PATH_MAX);
+  int path_max = pathconf(path.c_str(), _PC_PATH_MAX);
   if (path_max <= 0)
     path_max = 4096;
   char *buffer = (char *) malloc(path_max);
@@ -656,6 +656,6 @@ string remove_file_extension(const strin
 
 string lowercase(const string &str) {
   string result = str;
-  transform(str.begin(), str.end(), result.begin(), tolower);
+  transform(str.begin(), str.end(), result.begin(), (int(*)(int))tolower);
   return result;
 }
