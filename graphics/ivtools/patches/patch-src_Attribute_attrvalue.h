$NetBSD: patch-src_Attribute_attrvalue.h,v 1.1 2012/12/21 02:58:55 dholland Exp $

Silence extensive const warnings.

--- src/Attribute/attrvalue.h~	2009-08-11 19:39:25.000000000 +0000
+++ src/Attribute/attrvalue.h
@@ -39,9 +39,9 @@ class LeakChecker;
 #include <Unidraw/Components/compview.h>
 
 extern "C" {
-    int symbol_add(char*);
+    int symbol_add(const char*);
     int symbol_del(int);
-    int symbol_find(char*);
+    int symbol_find(const char*);
     char* symbol_pntr(int);
 }
 
