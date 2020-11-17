$NetBSD: patch-Lib_test_test__bytes.py,v 1.1 2020/11/17 19:33:26 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- Lib/test/test_bytes.py.orig	2020-08-15 05:20:16.000000000 +0000
+++ Lib/test/test_bytes.py
@@ -903,6 +903,7 @@ class BytesTest(BaseBytesTest, unittest.
             c_char_p)
 
         PyBytes_FromFormat = pythonapi.PyBytes_FromFormat
+        PyBytes_FromFormat.argtypes = (c_char_p,)
         PyBytes_FromFormat.restype = py_object
 
         # basic tests
