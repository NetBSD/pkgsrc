$NetBSD: patch-python_libxml2.py,v 1.1 2017/11/08 22:51:54 prlw1 Exp $

name[0:8] will fail if name is None.
https://bugzilla.gnome.org/show_bug.cgi?id=790071

--- python/libxml2.py.orig	2017-10-30 07:39:09.000000000 +0000
+++ python/libxml2.py
@@ -573,6 +573,8 @@ class xmlCoreBreadthFirstItertor:
 def nodeWrap(o):
     # TODO try to cast to the most appropriate node class
     name = libxml2mod.type(o)
+    if name is None:
+        return xmlNode(_obj=o)
     if name == "element" or name == "text":
         return xmlNode(_obj=o)
     if name == "attribute":
