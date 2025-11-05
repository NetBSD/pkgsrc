$NetBSD: patch-Lib_test_test__genericpath.py,v 1.1 2025/11/05 22:20:05 wiz Exp $

[3.14] gh-136065: Fix quadratic complexity in os.path.expandvars() (GH-134952) (GH-140844)
https://github.com/python/cpython/commit/631ba3407e3348ccd56ce5160c4fb2c5dc5f4d84

--- Lib/test/test_genericpath.py.orig	2025-10-07 09:34:52.000000000 +0000
+++ Lib/test/test_genericpath.py
@@ -7,9 +7,9 @@ import os
 import sys
 import unittest
 import warnings
-from test.support import (
-    is_apple, is_emscripten, os_helper, warnings_helper
-)
+from test import support
+from test.support import os_helper
+from test.support import warnings_helper
 from test.support.script_helper import assert_python_ok
 from test.support.os_helper import FakePath
 
@@ -445,6 +445,19 @@ class CommonTest(GenericTest):
                   os.fsencode('$bar%s bar' % nonascii))
             check(b'$spam}bar', os.fsencode('%s}bar' % nonascii))
 
+    @support.requires_resource('cpu')
+    def test_expandvars_large(self):
+        expandvars = self.pathmodule.expandvars
+        with os_helper.EnvironmentVarGuard() as env:
+            env.clear()
+            env["A"] = "B"
+            n = 100_000
+            self.assertEqual(expandvars('$A'*n), 'B'*n)
+            self.assertEqual(expandvars('${A}'*n), 'B'*n)
+            self.assertEqual(expandvars('$A!'*n), 'B!'*n)
+            self.assertEqual(expandvars('${A}A'*n), 'BA'*n)
+            self.assertEqual(expandvars('${'*10*n), '${'*10*n)
+
     def test_abspath(self):
         self.assertIn("foo", self.pathmodule.abspath("foo"))
         with warnings.catch_warnings():
@@ -502,7 +515,7 @@ class CommonTest(GenericTest):
             # directory (when the bytes name is used).
             and sys.platform not in {
                 "win32", "emscripten", "wasi"
-            } and not is_apple
+            } and not support.is_apple
         ):
             name = os_helper.TESTFN_UNDECODABLE
         elif os_helper.TESTFN_NONASCII:
