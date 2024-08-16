$NetBSD: patch-python_mozbuild_mozbuild_util.py,v 1.1 2024/08/16 10:20:40 nia Exp $

These python libraries were moved out of "collections" and their
original locations were deprecated.

--- python/mozbuild/mozbuild/util.py.orig	2024-08-16 10:00:10.087111758 +0000
+++ python/mozbuild/mozbuild/util.py
@@ -782,7 +782,7 @@ class HierarchicalStringList(object):
         self._strings = StrictOrderingOnAppendList()
         self._children = {}
 
-    class StringListAdaptor(collections.Sequence):
+    class StringListAdaptor(collections.abc.Sequence):
         def __init__(self, hsl):
             self._hsl = hsl
 
