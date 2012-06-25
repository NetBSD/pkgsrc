$NetBSD: patch-class.h,v 1.1 2012/06/25 11:16:00 joerg Exp $

Explicit template specialisation before implicit one.

--- class.h.orig	2012-06-23 16:32:11.000000000 +0000
+++ class.h
@@ -216,12 +216,12 @@ typedef int (*dbUDTComparator)(void*, vo
                                                  &dbDescribeComponentsOf##table)
 
 #define REGISTER_TEMPLATE_IN(table, database) \
-    GET_TABLE_DESC_PREFIX GB_NS::dbTableDescriptor* dbGetTableDescriptor GET_TABLE_DESC_PARAM(table) \
-      { return &table::dbDescriptor; }              \
     static GB_NS::dbFieldDescriptor* dbDescribeComponentsOf##table() \
-     { return ((table*)0)->dbDescribeComponents(NULL); }     \
+     { return ((table*)0)->dbDescribeComponents(NULL); } \
     TABLE_DESC_PREFIX GB_NS::dbTableDescriptor table::dbDescriptor(_T(#table), database, sizeof(table), \
-                                                            &dbDescribeComponentsOf##table)
+                                                            &dbDescribeComponentsOf##table); \
+    GET_TABLE_DESC_PREFIX GB_NS::dbTableDescriptor* dbGetTableDescriptor GET_TABLE_DESC_PARAM(table) \
+      { return &table::dbDescriptor; }              \
 
 #define REGISTER_IN_NS(ns, table, database)                              \
     GET_TABLE_DESC_PREFIX GB_NS::dbTableDescriptor* dbGetTableDescriptor GET_TABLE_DESC_PARAM(ns::table) \
