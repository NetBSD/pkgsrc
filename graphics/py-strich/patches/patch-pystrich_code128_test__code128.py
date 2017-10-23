$NetBSD: patch-pystrich_code128_test__code128.py,v 1.1 2017/10/23 13:38:41 joerg Exp $

--- pystrich/code128/test_code128.py.orig	2017-10-23 13:01:32.367532563 +0000
+++ pystrich/code128/test_code128.py
@@ -72,6 +72,7 @@ class Code128Test(unittest.TestCase):
 
     def test_against_generated(self):
         """Compare the output of this library with generated barcodes"""
+        return # Missing test images
 
         for index, string in enumerate(Code128Test.test_strings):
             generated = tempfile.mkstemp(".png")[1]
