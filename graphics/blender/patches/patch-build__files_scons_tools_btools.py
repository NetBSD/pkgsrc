$NetBSD: patch-build__files_scons_tools_btools.py,v 1.1 2012/12/03 13:15:51 ryoon Exp $

From Gentoo's 2.64a/0300-scons-failure.patch

--- build_files/scons/tools/btools.py.orig	2012-10-09 18:41:53.000000000 +0000
+++ build_files/scons/tools/btools.py
@@ -482,7 +482,9 @@ def read_opts(env, cfg, args):
         ('BF_3DMOUSE_LIB', '3d mouse library', ''),
         ('BF_3DMOUSE_LIBPATH', '3d mouse library path', ''),
         ('BF_3DMOUSE_LIB_STATIC', '3d mouse static library', ''),
+    ) # end of opts.AddOptions()
 
+    localopts.AddVariables(
         ('CFLAGS', 'C only flags', []),
         ('CCFLAGS', 'Generic C and C++ flags', []),
         ('CXXFLAGS', 'C++ only flags', []),
