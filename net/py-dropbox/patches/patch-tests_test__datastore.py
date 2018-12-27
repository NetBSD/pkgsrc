$NetBSD: patch-tests_test__datastore.py,v 1.1 2018/12/27 15:04:42 joerg Exp $

--- tests/test_datastore.py.orig	2018-12-25 21:57:44.460130334 +0000
+++ tests/test_datastore.py
@@ -226,7 +226,7 @@ class TestDatastoreManager(unittest.Test
             }
 
         # invoke code
-        token, dsinfos, deltamap = self.manager.await()
+        token, dsinfos, deltamap = self.manager.send_await()
 
         # check code
         self.assertEqual(token, 'notch')
@@ -241,7 +241,7 @@ class TestDatastoreManager(unittest.Test
             }
 
         # invoke code
-        token, dsinfos, deltamap = self.manager.await('notch')
+        token, dsinfos, deltamap = self.manager.send_await('notch')
 
         # check code
         self.assertEqual(token, 'notch')
@@ -262,7 +262,7 @@ class TestDatastoreManager(unittest.Test
             }
 
         # invoke code
-        token, dsinfos, deltamap = self.manager.await('notch', [ds])
+        token, dsinfos, deltamap = self.manager.send_await('notch', [ds])
 
         # check code
         self.assertEqual(token, 'notch')
@@ -286,7 +286,7 @@ class TestDatastoreManager(unittest.Test
             }
 
         # invoke code
-        token, dsinfos, deltamap = self.manager.await('notch', {ds: 42})
+        token, dsinfos, deltamap = self.manager.send_await('notch', {ds: 42})
 
         # check code
         self.assertEqual(token, 'notch')
@@ -310,7 +310,7 @@ class TestDatastoreManager(unittest.Test
             }
 
         # invoke code
-        token, dsinfos, deltamap = self.manager.await('notch', [ds])
+        token, dsinfos, deltamap = self.manager.send_await('notch', [ds])
 
         # check code
         self.assertEqual(token, 'notch')
