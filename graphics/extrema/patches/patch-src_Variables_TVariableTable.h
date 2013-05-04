$NetBSD: patch-src_Variables_TVariableTable.h,v 1.1 2013/05/04 12:46:01 joerg Exp $

--- src/Variables/TVariableTable.h.orig	2013-05-03 20:09:16.000000000 +0000
+++ src/Variables/TVariableTable.h
@@ -27,7 +27,7 @@ class TextVariable;
 class TVariableTable
 {
 private:
-  typedef std::map< wxString const, TextVariable* > TVariableMap;
+  typedef std::map< wxString, TextVariable* > TVariableMap;
   typedef TVariableMap::value_type entry_type;
 
  // TVariableTable is the table of pointers to TextVariables
