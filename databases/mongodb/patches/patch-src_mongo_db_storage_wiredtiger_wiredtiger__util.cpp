$NetBSD: patch-src_mongo_db_storage_wiredtiger_wiredtiger__util.cpp,v 1.1 2023/01/22 17:36:31 ryoon Exp $

--- src/mongo/db/storage/wiredtiger/wiredtiger_util.cpp.orig	2021-06-30 17:39:08.000000000 +0000
+++ src/mongo/db/storage/wiredtiger/wiredtiger_util.cpp
@@ -34,6 +34,7 @@
 #include "mongo/db/storage/wiredtiger/wiredtiger_util.h"
 
 #include <limits>
+#include <fstream>
 
 #include <boost/filesystem.hpp>
 #include <boost/filesystem/path.hpp>
@@ -80,7 +81,7 @@ void createTableChecksFile() {
     auto path = boost::filesystem::path(storageGlobalParams.dbpath) /
         boost::filesystem::path(kTableChecksFileName);
 
-    boost::filesystem::ofstream fileStream(path);
+    std::ofstream fileStream(path.c_str());
     fileStream << "This file indicates that a WiredTiger table check operation is in progress or "
                   "incomplete."
                << std::endl;
