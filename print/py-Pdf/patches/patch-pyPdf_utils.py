$NetBSD: patch-pyPdf_utils.py,v 1.1 2014/01/23 14:38:42 wiz Exp $

python-3.x compatibility.

--- pyPdf/utils.py.orig	2010-12-04 22:49:56.000000000 +0000
+++ pyPdf/utils.py
@@ -74,13 +74,13 @@ class ConvertFunctionsToVirtualList(obje
 
     def __getitem__(self, index):
         if not isinstance(index, int):
-            raise TypeError, "sequence indices must be integers"
+            raise TypeError("sequence indices must be integers")
         len_self = len(self)
         if index < 0:
             # support negative indexes
             index = len_self + index
         if index < 0 or index >= len_self:
-            raise IndexError, "sequence index out of range"
+            raise IndexError("sequence index out of range")
         return self.getFunction(index)
 
 def RC4_encrypt(key, plaintext):
@@ -117,6 +117,6 @@ class PageSizeNotDefinedError(PyPdfError
 if __name__ == "__main__":
     # test RC4
     out = RC4_encrypt("Key", "Plaintext")
-    print repr(out)
+    print(repr(out))
     pt = RC4_encrypt("Key", out)
-    print repr(pt)
+    print(repr(pt))
