$NetBSD: patch-giscanner_ccompiler.py,v 1.2 2019/06/03 10:47:20 prlw1 Exp $

Do not set LD_LIBRARY_PATH when calling the compiler.

--- giscanner/ccompiler.py.orig	2019-03-02 17:10:05.000000000 +0000
+++ giscanner/ccompiler.py
@@ -227,13 +227,6 @@ class CCompiler(object):
                 else:
                     args.append('-l' + library)
 
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
