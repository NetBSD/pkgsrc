$NetBSD: patch-build__files_scons_tools_btools.py,v 1.2 2014/07/09 20:01:08 ryoon Exp $

From Gentoo's 2.64a/0300-scons-failure.patch

--- build_files/scons/tools/btools.py.orig	2014-06-25 20:43:52.000000000 +0000
+++ build_files/scons/tools/btools.py
@@ -56,13 +56,7 @@ def get_version():
     raise Exception("%s: missing version string" % fname)
 
 def get_hash():
-    try:
-        build_hash = subprocess.check_output(['git', 'rev-parse', '--short', 'HEAD']).strip()
-    except OSError:
-        build_hash = None
-        print("WARNING: could not use git to retrieve current Blender repository hash...")
-    if build_hash == '' or build_hash == None:
-        build_hash = 'UNKNOWN'
+    build_hash = 'UNKNOWN'
 
     return build_hash
 
@@ -478,7 +472,9 @@ def read_opts(env, cfg, args):
         ('BF_3DMOUSE_LIB', '3d mouse library', ''),
         ('BF_3DMOUSE_LIBPATH', '3d mouse library path', ''),
         ('BF_3DMOUSE_LIB_STATIC', '3d mouse static library', ''),
+    ) # end of opts.AddOptions()
 
+    localopts.AddVariables(
         ('CFLAGS', 'C only flags', []),
         ('CCFLAGS', 'Generic C and C++ flags', []),
         ('CXXFLAGS', 'C++ only flags', []),
