$NetBSD: patch-Lib_test_test__ssl.py,v 1.3 2015/04/24 03:01:36 rodent Exp $

Fix build with LibreSSL.

--- Lib/test/test_ssl.py.orig	2014-12-10 15:59:47.000000000 +0000
+++ Lib/test/test_ssl.py
@@ -169,8 +169,9 @@ class BasicSocketTests(unittest.TestCase
             sys.stdout.write("\n RAND_status is %d (%s)\n"
                              % (v, (v and "sufficient randomness") or
                                 "insufficient randomness"))
-        self.assertRaises(TypeError, ssl.RAND_egd, 1)
-        self.assertRaises(TypeError, ssl.RAND_egd, 'foo', 1)
+        if hasattr(ssl, 'RAND_egd'):
+            self.assertRaises(TypeError, ssl.RAND_egd, 1)
+            self.assertRaises(TypeError, ssl.RAND_egd, 'foo', 1)
         ssl.RAND_add("this is a random string", 75.0)
 
     def test_parse_cert(self):
