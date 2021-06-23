$NetBSD: patch-Lib_test_test__unicode.py,v 1.1 2021/06/23 18:30:24 schmonz Exp $

macOS arm64 support, via MacPorts.

--- Lib/test/test_unicode.py.orig	2021-06-22 19:20:03.000000000 +0000
+++ Lib/test/test_unicode.py
@@ -1676,6 +1676,7 @@ class CAPITest(unittest.TestCase):
     def test_from_format(self):
         test_support.import_module('ctypes')
         from ctypes import (
+            c_char_p,
             pythonapi, py_object, sizeof,
             c_int, c_long, c_longlong, c_ssize_t,
             c_uint, c_ulong, c_ulonglong, c_size_t, c_void_p)
@@ -1684,6 +1685,7 @@ class CAPITest(unittest.TestCase):
         else:
             name = "PyUnicodeUCS4_FromFormat"
         _PyUnicode_FromFormat = getattr(pythonapi, name)
+        _PyUnicode_FromFormat.argtypes = (c_char_p,)
         _PyUnicode_FromFormat.restype = py_object
 
         def PyUnicode_FromFormat(format, *args):
