$NetBSD: patch-src_blockdiag_tests_test__utils__fontmap.py,v 1.1 2011/12/12 11:33:28 obache Exp $

* Fix testcase using 'with' statement are failed in python2.5 environment
  https://bitbucket.org/tk0miya/blockdiag/changeset/f078235db9b9

--- src/blockdiag/tests/test_utils_fontmap.py.orig	2011-11-21 02:38:58.000000000 +0000
+++ src/blockdiag/tests/test_utils_fontmap.py
@@ -3,7 +3,7 @@
 import os
 import sys
 import unittest2
-from utils import stderr_wrapper
+from utils import stderr_wrapper, assertRaises
 from cStringIO import StringIO
 from blockdiag.utils.collections import namedtuple
 from blockdiag.utils.fontmap import FontInfo, FontMap
@@ -31,33 +31,33 @@ class TestUtilsFontmap(unittest2.TestCas
         FontInfo("my-cursive", None, 11)
         FontInfo("-fantasy", None, 11)
 
+    @assertRaises(AttributeError)
     def test_fontinfo_invalid_familyname1(self):
-        with self.assertRaises(AttributeError):
-            FontInfo("unknown", None, 11)
+        FontInfo("unknown", None, 11)
 
+    @assertRaises(AttributeError)
     def test_fontinfo_invalid_familyname2(self):
-        with self.assertRaises(AttributeError):
-            FontInfo("sansserif-", None, 11)
+        FontInfo("sansserif-", None, 11)
 
+    @assertRaises(AttributeError)
     def test_fontinfo_invalid_familyname3(self):
-        with self.assertRaises(AttributeError):
-            FontInfo("monospace-unkown", None, 11)
+        FontInfo("monospace-unkown", None, 11)
 
+    @assertRaises(AttributeError)
     def test_fontinfo_invalid_familyname4(self):
-        with self.assertRaises(AttributeError):
-            FontInfo("cursive-bold-bold", None, 11)
+        FontInfo("cursive-bold-bold", None, 11)
 
+    @assertRaises(AttributeError)
     def test_fontinfo_invalid_familyname4(self):
-        with self.assertRaises(AttributeError):
-            FontInfo("SERIF", None, 11)
+        FontInfo("SERIF", None, 11)
 
+    @assertRaises(TypeError)
     def test_fontinfo_invalid_fontsize1(self):
-        with self.assertRaises(TypeError):
-            FontInfo("serif", None, None)
+        FontInfo("serif", None, None)
 
+    @assertRaises(ValueError)
     def test_fontinfo_invalid_fontsize2(self):
-        with self.assertRaises(ValueError):
-            FontInfo("serif", None, '')
+        FontInfo("serif", None, '')
 
     def test_fontinfo_parse(self):
         font = FontInfo("serif", None, 11)
@@ -212,15 +212,17 @@ class TestUtilsFontmap(unittest2.TestCas
         self.assertEqual(11, font1.size)
 
     def test_fontmap_duplicated_fontentry1(self):
-        _config = "[fontmap]\nsansserif: %s\nsansserif-normal: %s\n" % \
-                  (self.fontpath[0], self.fontpath[1])
-        config = StringIO(_config)
-        fmap = FontMap(config)
-
-        font1 = fmap.find()
-        self.assertEqual('sansserif', font1.generic_family)
-        self.assertEqual(self.fontpath[1], font1.path)
-        self.assertEqual(11, font1.size)
+        # this testcase is only for python2.6 or later
+        if sys.version_info > (2, 6):
+            _config = "[fontmap]\nsansserif: %s\nsansserif-normal: %s\n" % \
+                      (self.fontpath[0], self.fontpath[1])
+            config = StringIO(_config)
+            fmap = FontMap(config)
+
+            font1 = fmap.find()
+            self.assertEqual('sansserif', font1.generic_family)
+            self.assertEqual(self.fontpath[1], font1.path)
+            self.assertEqual(11, font1.size)
 
     @stderr_wrapper
     def test_fontmap_with_nodefault_fontentry(self):
