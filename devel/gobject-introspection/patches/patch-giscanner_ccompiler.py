$NetBSD: patch-giscanner_ccompiler.py,v 1.1 2018/02/06 15:44:01 jperkin Exp $

Do not set LD_LIBRARY_PATH when calling the compiler.

--- giscanner/ccompiler.py.orig	2017-05-18 05:42:52.000000000 +0000
+++ giscanner/ccompiler.py
@@ -161,13 +161,6 @@ class CCompiler(object):
 
             runtime_paths.append(library_path)
 
-        for envvar in runtime_path_envvar:
-            if envvar in os.environ:
-                os.environ[envvar] = \
-                    os.pathsep.join(runtime_paths + [os.environ[envvar]])
-            else:
-                os.environ[envvar] = os.pathsep.join(runtime_paths)
-
     def get_external_link_flags(self, args, libraries):
         # An "external" link is where the library to be introspected
         # is installed on the system; this case is used for the scanning
