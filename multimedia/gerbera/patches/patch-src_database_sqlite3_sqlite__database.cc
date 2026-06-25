$NetBSD: patch-src_database_sqlite3_sqlite__database.cc,v 1.1 2026/06/25 08:16:53 wiz Exp $

Fix build.
https://github.com/gerbera/gerbera/issues/3897

--- src/database/sqlite3/sqlite_database.cc.orig	2026-06-25 08:00:54.461931648 +0000
+++ src/database/sqlite3/sqlite_database.cc
@@ -179,7 +179,7 @@ void Sqlite3Database::run()
 
     // check for db-file
     if (!dbFile.isWritable())
-        throw DatabaseException("", fmt::format("Error while accessing sqlite database file ({}): {}", dbFilePath.c_str(), std::strerror(errno)));
+        throw DatabaseException("", fmt::format("Error while accessing sqlite database file ({}): {}", dbFilePath.c_str(), strerror(errno)));
 
     taskQueueOpen = true;
     threadRunner = std::make_unique<StdThreadRunner>(
@@ -188,7 +188,7 @@ void Sqlite3Database::run()
             inst->threadProc(); }, this);
 
     if (!threadRunner->isAlive()) {
-        throw DatabaseException("", fmt::format("Could not start sqlite thread: {}", std::strerror(errno)));
+        throw DatabaseException("", fmt::format("Could not start sqlite thread: {}", strerror(errno)));
     }
 
     // wait for sqlite3 thread to become ready
