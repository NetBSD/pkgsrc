$NetBSD: patch-bindings_python_setup.py,v 1.2 2021/02/25 19:47:51 leot Exp $

--- bindings/python/setup.py.orig	2020-10-21 11:34:41.000000000 +0000
+++ bindings/python/setup.py
@@ -208,13 +208,11 @@ class custom_build(build):
             log.info("Skipping building C extensions since LIBUNICORN_PATH is set")
         else:
             log.info("Building C extensions")
-            build_libraries()
         return build.run(self)
 
 class custom_develop(develop):
     def run(self):
         log.info("Building C extensions")
-        build_libraries()
         return develop.run(self)
 
 class custom_bdist_egg(bdist_egg):
