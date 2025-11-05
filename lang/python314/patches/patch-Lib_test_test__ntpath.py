$NetBSD: patch-Lib_test_test__ntpath.py,v 1.1 2025/11/05 22:20:05 wiz Exp $

[3.14] gh-136065: Fix quadratic complexity in os.path.expandvars() (GH-134952) (GH-140844)
https://github.com/python/cpython/commit/631ba3407e3348ccd56ce5160c4fb2c5dc5f4d84

--- Lib/test/test_ntpath.py.orig	2025-10-07 09:34:52.000000000 +0000
+++ Lib/test/test_ntpath.py
@@ -7,8 +7,7 @@ import sys
 import unittest
 import warnings
 from test import support
-from test.support import cpython_only, os_helper
-from test.support import TestFailed
+from test.support import os_helper
 from ntpath import ALLOW_MISSING
 from test.support.os_helper import FakePath
 from test import test_genericpath
@@ -59,7 +58,7 @@ def tester(fn, wantResult):
     fn = fn.replace("\\", "\\\\")
     gotResult = eval(fn)
     if wantResult != gotResult and _norm(wantResult) != _norm(gotResult):
-        raise TestFailed("%s should return: %s but returned: %s" \
+        raise support.TestFailed("%s should return: %s but returned: %s" \
               %(str(fn), str(wantResult), str(gotResult)))
 
     # then with bytes
@@ -75,7 +74,7 @@ def tester(fn, wantResult):
         warnings.simplefilter("ignore", DeprecationWarning)
         gotResult = eval(fn)
     if _norm(wantResult) != _norm(gotResult):
-        raise TestFailed("%s should return: %s but returned: %s" \
+        raise support.TestFailed("%s should return: %s but returned: %s" \
               %(str(fn), str(wantResult), repr(gotResult)))
 
 
@@ -1022,6 +1021,19 @@ class TestNtpath(NtpathTestCase):
             check('%spam%bar', '%sbar' % nonascii)
             check('%{}%bar'.format(nonascii), 'ham%sbar' % nonascii)
 
+    @support.requires_resource('cpu')
+    def test_expandvars_large(self):
+        expandvars = ntpath.expandvars
+        with os_helper.EnvironmentVarGuard() as env:
+            env.clear()
+            env["A"] = "B"
+            n = 100_000
+            self.assertEqual(expandvars('%A%'*n), 'B'*n)
+            self.assertEqual(expandvars('%A%A'*n), 'BA'*n)
+            self.assertEqual(expandvars("''"*n + '%%'), "''"*n + '%')
+            self.assertEqual(expandvars("%%"*n), "%"*n)
+            self.assertEqual(expandvars("$$"*n), "$"*n)
+
     def test_expanduser(self):
         tester('ntpath.expanduser("test")', 'test')
 
@@ -1439,7 +1451,7 @@ class TestNtpath(NtpathTestCase):
         self.assertTrue(os.path.exists(r"\\.\CON"))
 
     @unittest.skipIf(sys.platform != 'win32', "Fast paths are only for win32")
-    @cpython_only
+    @support.cpython_only
     def test_fast_paths_in_use(self):
         # There are fast paths of these functions implemented in posixmodule.c.
         # Confirm that they are being used, and not the Python fallbacks in
