$NetBSD: patch-Lib_test_test__platform.py,v 1.1 2021/06/23 18:30:24 schmonz Exp $

darwin20 support, via MacPorts.

--- Lib/test/test_platform.py.orig	2021-06-22 19:20:28.000000000 +0000
+++ Lib/test/test_platform.py
@@ -207,6 +207,11 @@ class PlatformTest(unittest.TestCase):
             fd.close()
             self.assertFalse(real_ver is None)
             result_list = res[0].split('.')
+            # macOS 11.0 (Big Sur) may report its version number
+            # as 10.16 if the executable is built with an older
+            # SDK target but sw_vers reports 11.0.
+            if result_list == ['10', '16']:
+                result_list = ['11', '0']
             expect_list = real_ver.split('.')
             len_diff = len(result_list) - len(expect_list)
             # On Snow Leopard, sw_vers reports 10.6.0 as 10.6
@@ -220,7 +225,7 @@ class PlatformTest(unittest.TestCase):
             self.assertEqual(res[1], ('', '', ''))
 
             if sys.byteorder == 'little':
-                self.assertIn(res[2], ('i386', 'x86_64'))
+                self.assertIn(res[2], ('i386', 'x86_64', 'arm64'))
             else:
                 self.assertEqual(res[2], 'PowerPC')
 
