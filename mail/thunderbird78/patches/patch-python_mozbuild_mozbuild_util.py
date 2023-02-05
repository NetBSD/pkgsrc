$NetBSD: patch-python_mozbuild_mozbuild_util.py,v 1.1 2023/02/05 08:32:24 he Exp $

Adjust for python 3.10

--- python/mozbuild/mozbuild/util.py.orig	2021-07-12 13:35:01.000000000 +0000
+++ python/mozbuild/mozbuild/util.py
@@ -782,7 +782,7 @@ class HierarchicalStringList(object):
         self._strings = StrictOrderingOnAppendList()
         self._children = {}
 
-    class StringListAdaptor(collections.Sequence):
+    class StringListAdaptor(collections.abc.Sequence):
         def __init__(self, hsl):
             self._hsl = hsl
 
