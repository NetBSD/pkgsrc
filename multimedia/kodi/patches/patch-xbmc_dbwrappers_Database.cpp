$NetBSD: patch-xbmc_dbwrappers_Database.cpp,v 1.1 2015/12/23 12:43:25 joerg Exp $

--- xbmc/dbwrappers/Database.cpp.orig	2015-12-22 17:53:05.000000000 +0000
+++ xbmc/dbwrappers/Database.cpp
@@ -127,7 +127,7 @@ void CDatabase::Split(const std::string&
   strFileName = strFileNameAndPath.substr(i);
 }
 
-std::string CDatabase::PrepareSQL(std::string strStmt, ...) const
+std::string CDatabase::PrepareSQL(const char *strStmt, ...) const
 {
   std::string strResult = "";
 
@@ -135,7 +135,7 @@ std::string CDatabase::PrepareSQL(std::s
   {
     va_list args;
     va_start(args, strStmt);
-    strResult = m_pDB->vprepare(strStmt.c_str(), args);
+    strResult = m_pDB->vprepare(strStmt, args);
     va_end(args);
   }
 
