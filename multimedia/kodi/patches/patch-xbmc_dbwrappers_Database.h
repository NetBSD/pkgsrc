$NetBSD: patch-xbmc_dbwrappers_Database.h,v 1.1 2015/12/23 12:43:25 joerg Exp $

Passing non-POD types to variadic functions is UB.

--- xbmc/dbwrappers/Database.h.orig	2015-12-22 18:37:20.000000000 +0000
+++ xbmc/dbwrappers/Database.h
@@ -71,7 +71,7 @@ public:
   void RollbackTransaction();
   bool InTransaction();
 
-  std::string PrepareSQL(std::string strStmt, ...) const;
+  std::string PrepareSQL(const char *strStmt, ...) const;
 
   /*!
    * @brief Get a single value from a table.
