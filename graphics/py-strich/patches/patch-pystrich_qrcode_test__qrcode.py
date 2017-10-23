$NetBSD: patch-pystrich_qrcode_test__qrcode.py,v 1.1 2017/10/23 13:38:41 joerg Exp $

--- pystrich/qrcode/test_qrcode.py.orig	2015-07-19 21:44:27.000000000 +0000
+++ pystrich/qrcode/test_qrcode.py
@@ -34,6 +34,7 @@ class QRTest(unittest.TestCase):
 
     def test_against_generated(self):
         """Compare the output of this library with generated barcodes"""
+        return # Missing test images
 
         i = 1
         for string in QRTest.test_strings:
