$NetBSD: patch-encfs_DirNode.cpp,v 1.2 2018/03/21 22:38:57 gdt Exp $

Define _DIRENT_HAVE_D_TYPE at the top for all the OSes that support
it. This is an untested functional change for FreeBSD and APPLE.

--- encfs/DirNode.cpp.orig	2018-01-28 21:07:41.000000000 +0000
+++ encfs/DirNode.cpp
@@ -42,6 +42,10 @@
 #include "NameIO.h"
 #include "easylogging++.h"
 
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__APPLE__)
+#define _DIRENT_HAVE_D_TYPE
+#endif
+
 using namespace std;
 
 namespace encfs {
