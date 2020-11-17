$NetBSD: patch-Lib_test_test__platform.py,v 1.1 2020/11/17 19:33:15 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- Lib/test/test_platform.py.orig	2020-09-23 12:36:32.000000000 +0000
+++ Lib/test/test_platform.py
@@ -217,7 +217,7 @@ class PlatformTest(unittest.TestCase):
             self.assertEqual(res[1], ('', '', ''))
 
             if sys.byteorder == 'little':
-                self.assertIn(res[2], ('i386', 'x86_64'))
+                self.assertIn(res[2], ('i386', 'x86_64', 'arm64'))
             else:
                 self.assertEqual(res[2], 'PowerPC')
 
