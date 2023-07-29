$NetBSD: patch-src_mongo_db_storage_storage__repair__observer.cpp,v 1.2 2023/07/29 11:45:43 adam Exp $

boost::filesystem::ofstream is deprected, use std::ofstream instead.

--- src/mongo/db/storage/storage_repair_observer.cpp.orig	2023-06-29 13:37:52.000000000 +0000
+++ src/mongo/db/storage/storage_repair_observer.cpp
@@ -34,6 +34,7 @@
 #include <algorithm>
 #include <cerrno>
 #include <cstring>
+#include <fstream>
 
 #ifdef __linux__
 #include <fcntl.h>
@@ -121,7 +122,7 @@ bool StorageRepairObserver::isDataInvali
 }
 
 void StorageRepairObserver::_touchRepairIncompleteFile() {
-    boost::filesystem::ofstream fileStream(_repairIncompleteFilePath);
+    std::ofstream fileStream(_repairIncompleteFilePath.string());
     fileStream << "This file indicates that a repair operation is in progress or incomplete.";
     if (fileStream.fail()) {
         LOGV2_FATAL_NOTRACE(50920,
