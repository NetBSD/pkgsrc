$NetBSD: patch-src_ZipArchive_ZipFile__stl.cpp,v 1.3 2012/08/12 02:12:51 marino Exp $

Add DragonFly support.

--- src/ZipArchive/ZipFile_stl.cpp.orig	2011-10-14 18:30:33 +0000
+++ src/ZipArchive/ZipFile_stl.cpp
@@ -16,7 +16,7 @@
 
 #if (defined _ZIP_IMPL_STL && (!defined _ZIP_FILE_IMPLEMENTATION || _ZIP_FILE_IMPLEMENTATION == ZIP_ZFI_DEFAULT)) || _ZIP_FILE_IMPLEMENTATION == ZIP_ZFI_STL
 
-#if defined __APPLE__ || defined __CYGWIN__ || defined __NetBSD__ 
+#if defined __APPLE__ || defined __CYGWIN__ || defined __NetBSD__ || defined __DragonFly__
 	#define FILE_FUNCTIONS_64B_BY_DEFAULT
 #else
 	#undef FILE_FUNCTIONS_64B_BY_DEFAULT	
