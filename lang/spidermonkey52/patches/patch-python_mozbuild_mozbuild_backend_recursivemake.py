$NetBSD: patch-python_mozbuild_mozbuild_backend_recursivemake.py,v 1.1 2018/05/16 11:36:36 youri Exp $

Copy headers instead of symlinking.

--- python/mozbuild/mozbuild/backend/recursivemake.py.orig	2018-04-28 01:04:06.000000000 +0000
+++ python/mozbuild/mozbuild/backend/recursivemake.py
@@ -1307,11 +1307,11 @@ class RecursiveMakeBackend(CommonBackend
                                 raise Exception("Wildcards are only supported in the filename part of "
                                                 "srcdir-relative or absolute paths.")
 
-                            install_manifest.add_pattern_symlink(basepath, wild, path)
+                            install_manifest.add_pattern_copy(basepath, wild, path)
                         else:
-                            install_manifest.add_pattern_symlink(f.srcdir, f, path)
+                            install_manifest.add_pattern_copy(f.srcdir, f, path)
                     else:
-                        install_manifest.add_symlink(f.full_path, dest)
+                        install_manifest.add_copy(f.full_path, dest)
                 else:
                     install_manifest.add_optional_exists(dest)
                     backend_file.write('%s_FILES += %s\n' % (
