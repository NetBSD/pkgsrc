$NetBSD: patch-Lib_test_test__dumbdbm.py,v 1.1 2015/03/03 17:19:58 snj Exp $

http://bugs.python.org/issue22885

--- Lib/test/test_dumbdbm.py.orig	2015-03-03 09:05:53.000000000 -0800
+++ Lib/test/test_dumbdbm.py	2015-03-03 09:10:02.000000000 -0800
@@ -160,6 +160,14 @@ class DumbDBMTestCase(unittest.TestCase)
             self.assertEqual(expected, got)
             f.close()
 
+    def test_eval(self):
+        with open(_fname + '.dir', 'w') as stream:
+            stream.write("str(__import__('sys').stdout.write('Hacked!')), 0\n")
+        with test_support.captured_stdout() as stdout:
+            with self.assertRaises(ValueError):
+                dumbdbm.open(_fname).close()
+            self.assertEqual(stdout.getvalue(), '')
+
     def tearDown(self):
         _delete_files()
 
