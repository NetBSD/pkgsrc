$NetBSD: patch-src_Variables_NVariableTable.h,v 1.1 2013/05/04 12:46:01 joerg Exp $

--- src/Variables/NVariableTable.h.orig	2013-05-03 20:13:43.000000000 +0000
+++ src/Variables/NVariableTable.h
@@ -28,7 +28,7 @@ class NumericVariable;
 class NVariableTable
 {
 private:
-  typedef std::map<wxString const,NumericVariable*> NVariableMap;
+  typedef std::map<wxString, NumericVariable*> NVariableMap;
   typedef NVariableMap::value_type entry_type;
 
   // NVariableTable is the table of pointers to NumericVariables
