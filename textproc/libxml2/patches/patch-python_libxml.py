$NetBSD: patch-python_libxml.py,v 1.1 2017/10/31 13:15:44 fhajny Exp $

--- python/libxml.py.orig	2004-09-28 05:59:58.000000000 -0500
+++ python/libxml.py
@@ -281,7 +281,7 @@ class xmlCore:
     # defined as python2 properties
     # 
     import sys
-    if float(sys.version[0:3]) < 2.2:
+    if float(sys.version[0:3].replace('p', '.')) < 2.2:
         def __getattr__(self, attr):
             if attr == "parent":
                 ret = libxml2mod.parent(self._o)
