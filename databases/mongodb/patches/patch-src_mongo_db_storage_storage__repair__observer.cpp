$NetBSD: patch-src_mongo_db_storage_storage__repair__observer.cpp,v 1.1 2023/01/22 17:36:31 ryoon Exp $

--- src/mongo/db/storage/storage_repair_observer.cpp.orig	2021-06-30 17:39:08.000000000 +0000
+++ src/mongo/db/storage/storage_repair_observer.cpp
@@ -34,6 +34,7 @@
 #include <algorithm>
 #include <cerrno>
 #include <cstring>
+#include <fstream>
 
 #ifdef __linux__
 #include <fcntl.h>
@@ -120,7 +121,7 @@ bool StorageRepairObserver::isDataInvali
 }
 
 void StorageRepairObserver::_touchRepairIncompleteFile() {
-    boost::filesystem::ofstream fileStream(_repairIncompleteFilePath);
+    std::ofstream fileStream(_repairIncompleteFilePath);
     fileStream << "This file indicates that a repair operation is in progress or incomplete.";
     if (fileStream.fail()) {
         severe() << "Failed to write to file " << _repairIncompleteFilePath.string() << ": "
