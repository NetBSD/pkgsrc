$NetBSD: patch-third__party_python_gyp_pylib_gyp_common.py,v 1.1 2022/12/27 20:08:45 abs Exp $

Adjust for python 3.10

--- third_party/python/gyp/pylib/gyp/common.py.orig	2021-07-12 13:35:05.000000000 +0000
+++ third_party/python/gyp/pylib/gyp/common.py
@@ -494,7 +494,7 @@ def uniquer(seq, idfun=None):
 
 
 # Based on http://code.activestate.com/recipes/576694/.
-class OrderedSet(collections.MutableSet):
+class OrderedSet(collections.abc.MutableSet):
   def __init__(self, iterable=None):
     self.end = end = []
     end += [None, end, end]         # sentinel node for doubly linked list
