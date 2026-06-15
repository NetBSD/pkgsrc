$NetBSD: patch-src_table.c,v 1.1 2026/06/15 07:36:25 nia Exp $

Avoid using bool as a variable name, it conflicts with the C keyword/typedef.

--- src/table.c.orig	2026-06-15 07:32:35.496258584 +0000
+++ src/table.c
@@ -1277,10 +1277,10 @@ void pr_table_dump(void (*dumpf)(const char *fmt, ...)
   }
 }
 
-int table_handling_signal(int bool) {
-  if (bool == TRUE ||
-      bool == FALSE) {
-    handling_signal = bool;
+int table_handling_signal(int boolvar) {
+  if (boolvar == TRUE ||
+      boolvar == FALSE) {
+    handling_signal = boolvar;
     return 0;
   }
 
