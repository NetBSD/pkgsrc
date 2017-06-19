$NetBSD: patch-encfs_DirNode.cpp,v 1.1 2017/06/19 18:41:39 maya Exp $

Define _DIRENT_HAVE_D_TYPE at the top for all the OSes that support
it. This is an untested functional change for FreeBSD and APPLE.

--- encfs/DirNode.cpp.orig	2016-09-18 20:16:04.000000000 +0000
+++ encfs/DirNode.cpp
@@ -42,6 +42,10 @@
 #include "Error.h"
 #include "Mutex.h"
 
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__APPLE__)
+#define _DIRENT_HAVE_D_TYPE
+#endif
+
 using namespace std;
 
 namespace encfs {
@@ -78,7 +82,7 @@ static bool _nextName(struct dirent *&de
 
   if (de) {
     if (fileType) {
-#if defined(_DIRENT_HAVE_D_TYPE) || defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(_DIRENT_HAVE_D_TYPE)
       *fileType = de->d_type;
 #else
 #warning "struct dirent.d_type not supported"
