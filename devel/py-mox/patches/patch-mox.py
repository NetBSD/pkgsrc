$NetBSD: patch-mox.py,v 1.1 2018/03/24 17:10:07 joerg Exp $

--- mox.py.orig	2018-03-24 14:35:50.526907676 +0000
+++ mox.py
@@ -1229,7 +1229,7 @@ class Comparator:
       rhs: any python object
     """
 
-    raise NotImplementedError, 'method must be implemented by a subclass.'
+    raise NotImplementedError('method must be implemented by a subclass.')
 
   def __eq__(self, rhs):
     return self.equals(rhs)
