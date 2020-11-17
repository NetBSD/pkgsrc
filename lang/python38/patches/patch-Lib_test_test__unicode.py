$NetBSD: patch-Lib_test_test__unicode.py,v 1.1 2020/11/17 19:33:15 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- Lib/test/test_unicode.py.orig	2020-09-23 12:36:32.000000000 +0000
+++ Lib/test/test_unicode.py
@@ -2454,11 +2454,13 @@ class CAPITest(unittest.TestCase):
     def test_from_format(self):
         support.import_module('ctypes')
         from ctypes import (
+            c_char_p,
             pythonapi, py_object, sizeof,
             c_int, c_long, c_longlong, c_ssize_t,
             c_uint, c_ulong, c_ulonglong, c_size_t, c_void_p)
         name = "PyUnicode_FromFormat"
         _PyUnicode_FromFormat = getattr(pythonapi, name)
+        _PyUnicode_FromFormat.argtypes = (c_char_p,)
         _PyUnicode_FromFormat.restype = py_object
 
         def PyUnicode_FromFormat(format, *args):
