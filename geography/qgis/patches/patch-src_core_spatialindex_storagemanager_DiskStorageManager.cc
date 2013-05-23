$NetBSD: patch-src_core_spatialindex_storagemanager_DiskStorageManager.cc,v 1.1 2013/05/23 15:03:27 joerg Exp $

--- src/core/spatialindex/storagemanager/DiskStorageManager.cc.orig	2013-05-23 14:06:42.000000000 +0000
+++ src/core/spatialindex/storagemanager/DiskStorageManager.cc
@@ -26,6 +26,7 @@
 #include <sys/stat.h>
 #include <stdio.h>
 #include <cstring>
+#include <unistd.h>
 
 #ifdef WIN32
 #include <io.h>
