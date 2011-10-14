$NetBSD: patch-src_ZipArchive_ZipPlatform__lnx.cpp,v 1.1 2011/10/14 09:49:07 ryoon Exp $

Add DragonFly support.

--- src/ZipArchive/ZipPlatform_lnx.cpp.orig	2011-10-14 18:30:33 +0000
+++ src/ZipArchive/ZipPlatform_lnx.cpp
@@ -16,7 +16,7 @@
 
 #ifdef _ZIP_SYSTEM_LINUX
 
-#if defined __APPLE__ || defined __CYGWIN__ || defined __NetBSD__ 
+#if defined __APPLE__ || defined __CYGWIN__ || defined __NetBSD__ || defined __DragonFly__
 	#define FILE_FUNCTIONS_64B_BY_DEFAULT
 #else
 	#undef FILE_FUNCTIONS_64B_BY_DEFAULT	
@@ -34,7 +34,7 @@
 
 #include <sys/types.h>
 
-#if defined (__FreeBSD__) || defined (__APPLE__) || defined (__NetBSD__)
+#if defined (__FreeBSD__) || defined (__APPLE__) || defined (__NetBSD__) || defined (__DragonFly__)
 	#include <sys/param.h>
 	#include <sys/mount.h>
 #else
