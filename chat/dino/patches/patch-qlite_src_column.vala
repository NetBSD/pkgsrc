$NetBSD: patch-qlite_src_column.vala,v 1.1 2021/05/01 08:53:59 nia Exp $

[PATCH] QLite: Adjust Real for latest vala version
https://github.com/dino/dino/commit/9acb54df9254609f2fe4de83c9047d408412de28.patch

--- qlite/src/column.vala.orig	2020-11-12 18:00:00.000000000 +0000
+++ qlite/src/column.vala
@@ -96,12 +96,14 @@ public abstract class Column<T> {
         }
     }
 
-    public class Real : Column<double> {
-        public Real(string name) {
+    public class NullableReal : Column<double?> {
+        public NullableReal(string name) {
             base(name, FLOAT);
         }
 
-        public override double get(Row row, string? table_name = DEFALT_TABLE_NAME) {
+        public override bool not_null { get { return false; } set {} }
+
+        public override double? get(Row row, string? table_name = DEFALT_TABLE_NAME) {
             return row.get_real(name, table_name == DEFALT_TABLE_NAME ? table.name : table_name);
         }
 
@@ -109,7 +111,7 @@ public abstract class Column<T> {
             return !row.has_real(name, table_name == DEFALT_TABLE_NAME ? table.name : table_name);
         }
 
-        internal override void bind(Statement stmt, int index, double value) {
+        internal override void bind(Statement stmt, int index, double? value) {
             stmt.bind_double(index, value);
         }
     }
