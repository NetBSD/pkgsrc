$NetBSD: patch-.._.._python_mozbuild_mozbuild_backend_recursivemake.py,v 1.1 2020/04/06 04:58:42 wiz Exp $

Copy headers on install instead of symlinking

--- ../../python/mozbuild/mozbuild/backend/recursivemake.py.orig	2019-07-01 09:07:46.000000000 +0000
+++ ../../python/mozbuild/mozbuild/backend/recursivemake.py
@@ -1427,11 +1427,11 @@ class RecursiveMakeBackend(CommonBackend
                                 raise Exception("Wildcards are only supported in the filename part of "
                                                 "srcdir-relative or absolute paths.")
 
-                            install_manifest.add_pattern_link(basepath, wild, path)
+                            install_manifest.add_pattern_copy(basepath, wild, path)
                         else:
-                            install_manifest.add_pattern_link(f.srcdir, f, path)
+                            install_manifest.add_pattern_copy(f.srcdir, f, path)
                     else:
-                        install_manifest.add_link(f.full_path, dest)
+                        install_manifest.add_copy(f.full_path, dest)
                 else:
                     install_manifest.add_optional_exists(dest)
                     backend_file.write('%s_FILES += %s\n' % (
