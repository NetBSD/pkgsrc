$NetBSD: patch-Lib_test_test__bytes.py,v 1.1 2020/11/12 10:58:21 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Backported from:
https://github.com/python/cpython/pull/22855

--- Lib/test/test_bytes.py.orig	2020-10-05 15:07:58.000000000 +0000
+++ Lib/test/test_bytes.py
@@ -1034,6 +1034,7 @@ class BytesTest(BaseBytesTest, unittest.
             c_char_p)
 
         PyBytes_FromFormat = pythonapi.PyBytes_FromFormat
+        PyBytes_FromFormat.argtypes = (c_char_p,)
         PyBytes_FromFormat.restype = py_object
 
         # basic tests
