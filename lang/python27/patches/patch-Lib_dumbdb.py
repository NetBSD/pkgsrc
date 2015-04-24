$NetBSD: patch-Lib_dumbdb.py,v 1.2 2015/04/24 03:01:36 rodent Exp $

http://bugs.python.org/issue22885

--- Lib/dumbdbm.py.orig	2014-12-10 15:59:35.000000000 +0000
+++ Lib/dumbdbm.py
@@ -21,6 +21,7 @@ is read when the database is opened, and
 
 """
 
+import ast as _ast
 import os as _os
 import __builtin__
 import UserDict
@@ -85,7 +86,7 @@ class _Database(UserDict.DictMixin):
             with f:
                 for line in f:
                     line = line.rstrip()
-                    key, pos_and_siz_pair = eval(line)
+                    key, pos_and_siz_pair = _ast.literal_eval(line)
                     self._index[key] = pos_and_siz_pair
 
     # Write the index dict to the directory file.  The original directory
