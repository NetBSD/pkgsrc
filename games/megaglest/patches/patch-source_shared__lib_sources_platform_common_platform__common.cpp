$NetBSD: patch-source_shared__lib_sources_platform_common_platform__common.cpp,v 1.1 2019/09/08 20:54:16 nia Exp $

Support NetBSD.

--- source/shared_lib/sources/platform/common/platform_common.cpp.orig	2017-03-08 20:39:12.000000000 +0000
+++ source/shared_lib/sources/platform/common/platform_common.cpp
@@ -1093,7 +1093,7 @@ uint32 getFolderTreeContentsCheckSumRecu
 	glob_t globbuf;
 
 	int res = glob(mypath.c_str(), 0, 0, &globbuf);
-#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
 	if(res < 0) {
 		std::stringstream msg;
 		msg << "#2 Couldn't scan directory '" << mypath << "': " << strerror(errno);
@@ -1127,13 +1127,13 @@ uint32 getFolderTreeContentsCheckSumRecu
 	globfree(&globbuf);
 
     // Look recursively for sub-folders
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 	res = glob(mypath.c_str(), 0, 0, &globbuf);
 #else
 	res = glob(mypath.c_str(), GLOB_ONLYDIR, 0, &globbuf);
 #endif
 
-#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
 	if(res < 0) {
 		std::stringstream msg;
 		msg << "#3 Couldn't scan directory '" << mypath << "': " << strerror(errno);
@@ -1142,7 +1142,7 @@ uint32 getFolderTreeContentsCheckSumRecu
 #endif
 
 	for(int i = 0; i < (int)globbuf.gl_pathc; ++i) {
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 		struct stat statStruct;
 		// only process if dir..
 		lstat( globbuf.gl_pathv[i], &statStruct);
@@ -1274,7 +1274,7 @@ vector<string> getFolderTreeContentsList
 	}
 
 	int res = glob(mypath.c_str(), globFlags, 0, &globbuf);
-#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
 	if(res < 0) {
 		std::stringstream msg;
 		msg << "#4 Couldn't scan directory '" << mypath << "': " << strerror(errno);
@@ -1307,14 +1307,14 @@ vector<string> getFolderTreeContentsList
 	globfree(&globbuf);
 
     // Look recursively for sub-folders
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 	res = glob(mypath.c_str(), 0, 0, &globbuf);
 #else //APPLE doesn't have the GLOB_ONLYDIR definition..
 	globFlags |= GLOB_ONLYDIR;
 	res = glob(mypath.c_str(), globFlags, 0, &globbuf);
 #endif
 
-#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
 	if(res < 0) {
 		std::stringstream msg;
 		msg << "#5 Couldn't scan directory '" << mypath << "': " << strerror(errno);
@@ -1323,7 +1323,7 @@ vector<string> getFolderTreeContentsList
 #endif
 
 	for(int i = 0; i < (int)globbuf.gl_pathc; ++i) {
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 		struct stat statStruct;
 		// only get if dir..
 		lstat( globbuf.gl_pathv[ i], &statStruct);
@@ -1415,7 +1415,7 @@ vector<std::pair<string,uint32> > getFol
 
 	int res = glob(mypath.c_str(), 0, 0, &globbuf);
 
-#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
 	if(res < 0) {
 		std::stringstream msg;
 		msg << "#6 Couldn't scan directory '" << mypath << "': " << strerror(errno);
@@ -1447,13 +1447,13 @@ vector<std::pair<string,uint32> > getFol
 	globfree(&globbuf);
 
     // Look recursively for sub-folders
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 	res = glob(mypath.c_str(), 0, 0, &globbuf);
 #else //APPLE doesn't have the GLOB_ONLYDIR definition..
 	res = glob(mypath.c_str(), GLOB_ONLYDIR, 0, &globbuf);
 #endif
 
-#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
 	if(res < 0) {
 		std::stringstream msg;
 		msg << "#7 Couldn't scan directory '" << mypath << "': " << strerror(errno);
@@ -1462,7 +1462,7 @@ vector<std::pair<string,uint32> > getFol
 #endif
 
 	for(int i = 0; i < (int)globbuf.gl_pathc; ++i) {
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 		struct stat statStruct;
 		// only get if dir..
 		lstat( globbuf.gl_pathv[ i], &statStruct);
