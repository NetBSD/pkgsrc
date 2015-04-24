$NetBSD: patch-Lib_test_test__ssl.py,v 1.1 2015/04/24 03:24:32 rodent Exp $

Fix build with LibreSSL.

--- Lib/test/test_ssl.py.orig	2014-10-12 07:03:53.000000000 +0000
+++ Lib/test/test_ssl.py
@@ -130,8 +130,9 @@ class BasicSocketTests(unittest.TestCase
         self.assertRaises(ValueError, ssl.RAND_bytes, -5)
         self.assertRaises(ValueError, ssl.RAND_pseudo_bytes, -5)
 
-        self.assertRaises(TypeError, ssl.RAND_egd, 1)
-        self.assertRaises(TypeError, ssl.RAND_egd, 'foo', 1)
+        if hasattr(ssl, 'RAND_egd'):
+            self.assertRaises(TypeError, ssl.RAND_egd, 1)
+            self.assertRaises(TypeError, ssl.RAND_egd, 'foo', 1)
         ssl.RAND_add("this is a random string", 75.0)
 
     @unittest.skipUnless(os.name == 'posix', 'requires posix')
