$NetBSD: patch-src_mongo_db_storage_wiredtiger_wiredtiger__kv__engine.cpp,v 1.1 2023/07/29 11:45:43 adam Exp $

boost::filesystem::ofstream deprected, use std::ofstream instead.

--- src/mongo/db/storage/wiredtiger/wiredtiger_kv_engine.cpp.orig	2023-07-26 16:17:08.000000000 +0000
+++ src/mongo/db/storage/wiredtiger/wiredtiger_kv_engine.cpp
@@ -43,6 +43,7 @@
 
 #include <fmt/format.h>
 #include <iomanip>
+#include <fstream>
 #include <memory>
 
 #include "mongo/db/storage/wiredtiger/wiredtiger_kv_engine.h"
@@ -1268,7 +1269,7 @@ WiredTigerKVEngine::beginNonBlockingBack
 
     // Create ongoingBackup.lock file to signal recovery that it should delete WiredTiger.backup if
     // we have an unclean shutdown with the cursor still open.
-    { boost::filesystem::ofstream ongoingBackup(getOngoingBackupPath()); }
+    { std::ofstream ongoingBackup(getOngoingBackupPath().string()); }
 
     // Oplog truncation thread won't remove oplog since the checkpoint pinned by the backup cursor.
     stdx::lock_guard<Latch> lock(_oplogPinnedByBackupMutex);
