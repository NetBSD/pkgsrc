$NetBSD: patch-build__files_scons_tools_btools.py,v 1.3 2015/12/15 09:46:27 markd Exp $

From Gentoo's 2.64a/0300-scons-failure.patch

--- build_files/scons/tools/btools.py.orig	2015-04-01 02:44:23.000000000 +0000
+++ build_files/scons/tools/btools.py
@@ -71,16 +71,7 @@ def get_version():
     raise Exception("%s: missing version string" % fname)
 
 def get_hash():
-    try:
-        build_hash = get_command_output(['git', 'rev-parse', '--short', 'HEAD']).strip()
-    except OSError:
-        build_hash = None
-        print("WARNING: could not use git to retrieve current Blender repository hash...")
-    except subprocess.CalledProcessError as e:
-        build_hash = None
-        print("WARNING: git errored while retrieving current Blender repository hash (%d)..." % e.returncode)
-    if build_hash == '' or build_hash == None:
-        build_hash = 'UNKNOWN'
+    build_hash = 'UNKNOWN'
 
     return build_hash
 
@@ -517,7 +508,9 @@ def read_opts(env, cfg, args):
         ('BF_3DMOUSE_LIB', '3d mouse library', ''),
         ('BF_3DMOUSE_LIBPATH', '3d mouse library path', ''),
         ('BF_3DMOUSE_LIB_STATIC', '3d mouse static library', ''),
+    ) # end of opts.AddOptions()
 
+    localopts.AddVariables(
         ('CFLAGS', 'C only flags', []),
         ('CCFLAGS', 'Generic C and C++ flags', []),
         ('CXXFLAGS', 'C++ only flags', []),
