$NetBSD: patch-sx_pisa3_pisa__reportlab.py,v 1.1 2017/06/29 20:02:02 joerg Exp $

--- sx/pisa3/pisa_reportlab.py.orig	2017-06-29 13:03:23.461320659 +0000
+++ sx/pisa3/pisa_reportlab.py
@@ -327,7 +327,10 @@ class PmlImageReader(object):
                 elif mode not in ('L', 'RGB', 'CMYK'):
                     im = im.convert('RGB')
                     self.mode = 'RGB'
-                self._data = im.tostring()        
+                if hasattr(im, "tobytes"):
+                    self._data = im.tobytes()
+                else:
+                    self._data = im.tostring()
         return self._data
 
     def getImageData(self):
