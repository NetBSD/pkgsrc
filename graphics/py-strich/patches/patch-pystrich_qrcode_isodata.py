$NetBSD: patch-pystrich_qrcode_isodata.py,v 1.1 2017/10/23 13:38:41 joerg Exp $

--- pystrich/qrcode/isodata.py.orig	2015-07-19 21:44:27.000000000 +0000
+++ pystrich/qrcode/isodata.py
@@ -1,6 +1,7 @@
 """ISO/IEC 18004:2006 tables and functions implementation"""
 
 import os.path
+import sys
 
 MAX_DATA_BITS = [
     128, 224, 352, 512, 688, 864, 992, 1232, 1456, 1728,
@@ -50,7 +51,10 @@ class MatrixInfo:
         filename = path + "/qrv" + str(version) + "_"
         filename += str(ecl) + ".dat"
 
-        unpack = list
+        if sys.version_info.major == 2:
+            unpack = lambda y: [ord(x) for x in y]
+        else:
+            unpack = list
 
         with open(filename, "rb") as fhndl:
             self.matrix_d = []
