$NetBSD: patch-xbmc_dialogs_GUIDialogMediaFilter.cpp,v 1.1 2015/12/23 12:43:25 joerg Exp $

--- xbmc/dialogs/GUIDialogMediaFilter.cpp.orig	2015-12-22 17:56:43.000000000 +0000
+++ xbmc/dialogs/GUIDialogMediaFilter.cpp
@@ -888,7 +888,7 @@ bool CGUIDialogMediaFilter::GetMinMax(co
     return false;
   }
 
-  std::string strSQL = "SELECT %s FROM %s ";
+  const char *strSQL = "SELECT %s FROM %s ";
 
   min = static_cast<int>(strtol(db->GetSingleValue(db->PrepareSQL(strSQL, std::string("MIN(" + field + ")").c_str(), table.c_str()) + strSQLExtra).c_str(), NULL, 0));
   max = static_cast<int>(strtol(db->GetSingleValue(db->PrepareSQL(strSQL, std::string("MAX(" + field + ")").c_str(), table.c_str()) + strSQLExtra).c_str(), NULL, 0));
