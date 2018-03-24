$NetBSD: patch-bindings_python_setup.py,v 1.1 2018/03/24 17:09:34 joerg Exp $

--- bindings/python/setup.py.orig	2018-03-24 14:17:22.780317467 +0000
+++ bindings/python/setup.py
@@ -195,7 +195,6 @@ class custom_sdist(sdist):
 class custom_build(build):
     def run(self):
         log.info("Building C extensions")
-        build_libraries()
         return build.run(self)
 
 class custom_bdist_egg(bdist_egg):
@@ -235,7 +234,6 @@ try:
     class custom_develop(develop):
         def run(self):
             log.info("Building C extensions")
-            build_libraries()
             return develop.run(self)
 
     cmdclass['develop'] = custom_develop
