$NetBSD: patch-setup.py,v 1.4 2018/06/18 11:17:54 adam Exp $

Allow newer py-flakes.
Add support for pycodestyle-2.4.0.

From upstream commits 0273ca56, 85c503de, 68782675, e61d9d24, ef1d5cee.

--- setup.py.orig	2017-08-08 00:31:43.000000000 +0000
+++ setup.py
@@ -21,8 +21,8 @@ requires = [
     # http://flake8.pycqa.org/en/latest/faq.html#why-does-flake8-use-ranges-for-its-dependencies
     # And in which releases we will update those ranges here:
     # http://flake8.pycqa.org/en/latest/internal/releases.html#releasing-flake8
-    "pyflakes >= 1.5.0, < 1.7.0",
-    "pycodestyle >= 2.0.0, < 2.4.0",
+    "pyflakes >= 1.5.0",
+    "pycodestyle >= 2.4.0",
     "mccabe >= 0.6.0, < 0.7.0",
     "setuptools >= 30",
 ]
@@ -108,7 +108,8 @@ setuptools.setup(
             PEP8_PLUGIN('module_imports_on_top_of_file'),
             PEP8_PLUGIN('compound_statements'),
             PEP8_PLUGIN('explicit_line_join'),
-            PEP8_PLUGIN('break_around_binary_operator'),
+            PEP8_PLUGIN('break_after_binary_operator'),
+            PEP8_PLUGIN('break_before_binary_operator'),
             PEP8_PLUGIN('comparison_to_singleton'),
             PEP8_PLUGIN('comparison_negative'),
             PEP8_PLUGIN('comparison_type'),
@@ -118,6 +119,8 @@ setuptools.setup(
             PEP8_PLUGIN('python_3000_raise_comma'),
             PEP8_PLUGIN('python_3000_not_equal'),
             PEP8_PLUGIN('python_3000_backticks'),
+            PEP8_PLUGIN('python_3000_invalid_escape_sequence'),
+            PEP8_PLUGIN('python_3000_async_await_keywords'),
         ],
         'flake8.report': [
             'default = flake8.formatting.default:Default',
