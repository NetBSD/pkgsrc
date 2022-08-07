$NetBSD: patch-src_test-repacker.cc,v 1.1 2022/08/07 12:35:35 tnn Exp $

https://github.com/harfbuzz/harfbuzz/commit/04d28d94e576aab099891e6736fd0088dfac3366

--- src/test-repacker.cc.orig	2022-07-31 13:50:44.000000000 +0000
+++ src/test-repacker.cc
@@ -112,9 +112,9 @@ static void start_lookup (int8_t type,
                           hb_serialize_context_t* c)
 {
   char lookup[] = {
-    0, type, // type
+    0, (char)type, // type
     0, 0, // flag
-    0, num_subtables, // num subtables
+    0, (char)num_subtables, // num subtables
   };
 
   start_object (lookup, 6, c);
