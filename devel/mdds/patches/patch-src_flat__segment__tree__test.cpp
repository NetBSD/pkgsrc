$NetBSD: patch-src_flat__segment__tree__test.cpp,v 1.1 2015/08/12 00:45:18 ryoon Exp $

https://gerrit.libreoffice.org/gitweb?p=core.git;a=commit;h=bead58cb4042ac42dee890e2f21ab7ea81136e54

--- src/flat_segment_tree_test.cpp.orig	2015-06-11 23:53:55.000000000 +0000
+++ src/flat_segment_tree_test.cpp
@@ -1943,6 +1943,10 @@ void fst_test_non_numeric_value()
     db.search(1, result);
 
     assert(result == "hello world");
+
+    db_type db2(db);
+
+    assert(db == db2);
 }
 
 void fst_test_non_numeric_key()
