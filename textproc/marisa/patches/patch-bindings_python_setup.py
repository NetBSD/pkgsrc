$NetBSD: patch-bindings_python_setup.py,v 1.1 2014/05/24 10:21:13 obache Exp $

add version for egg file's file name.

--- bindings/python/setup.py.orig	2011-05-14 05:20:52.000000000 +0000
+++ bindings/python/setup.py
@@ -5,5 +5,6 @@ marisa_module = Extension("_marisa",
                           libraries=["marisa"])
 
 setup(name = "marisa",
+      version = "@VERSION@",
       ext_modules = [marisa_module],
       py_modules = ["marisa"])
