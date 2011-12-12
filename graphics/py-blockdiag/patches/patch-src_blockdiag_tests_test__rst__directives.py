$NetBSD: patch-src_blockdiag_tests_test__rst__directives.py,v 1.1 2011/12/12 11:33:28 obache Exp $

* Fix testcase using 'with' statement are failed in python2.5 environment
  https://bitbucket.org/tk0miya/blockdiag/changeset/f078235db9b9

--- src/blockdiag/tests/test_rst_directives.py.orig	2011-11-21 02:41:13.000000000 +0000
+++ src/blockdiag/tests/test_rst_directives.py
@@ -5,7 +5,7 @@ import os
 import sys
 import tempfile
 import unittest2
-from utils import stderr_wrapper
+from utils import stderr_wrapper, assertRaises
 from docutils import nodes
 from docutils.core import publish_doctree
 from docutils.parsers.rst import directives as docutils
@@ -150,20 +150,20 @@ class TestRstDirectives(unittest2.TestCa
         self.assertFalse('target' in doctree[0])
 
     @use_tmpdir
+    @assertRaises(RuntimeError)
     def test_rst_directives_with_block_fontpath1(self, path):
-        with self.assertRaises(RuntimeError):
-            directives.setup(format='SVG', fontpath=['dummy.ttf'],
-                             outputdir=path)
-            text = ".. blockdiag::\n   :alt: hello world\n\n   { A -> B }"
-            doctree = publish_doctree(text)
+        directives.setup(format='SVG', fontpath=['dummy.ttf'],
+                         outputdir=path)
+        text = ".. blockdiag::\n   :alt: hello world\n\n   { A -> B }"
+        doctree = publish_doctree(text)
 
     @use_tmpdir
+    @assertRaises(RuntimeError)
     def test_rst_directives_with_block_fontpath2(self, path):
-        with self.assertRaises(RuntimeError):
-            directives.setup(format='SVG', fontpath='dummy.ttf',
-                             outputdir=path)
-            text = ".. blockdiag::\n   :alt: hello world\n\n   { A -> B }"
-            doctree = publish_doctree(text)
+        directives.setup(format='SVG', fontpath='dummy.ttf',
+                         outputdir=path)
+        text = ".. blockdiag::\n   :alt: hello world\n\n   { A -> B }"
+        doctree = publish_doctree(text)
 
     @use_tmpdir
     def test_rst_directives_with_block_maxwidth(self, path):
