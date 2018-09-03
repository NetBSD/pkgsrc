$NetBSD: patch-mesonbuild_minstall.py,v 1.1 2018/09/03 09:30:25 wiz Exp $

Don't touch rpath.

--- mesonbuild/minstall.py.orig	2018-06-22 11:50:56.000000000 +0000
+++ mesonbuild/minstall.py
@@ -436,15 +436,6 @@ class Installer:
                         print("Symlink creation does not work on this platform. "
                               "Skipping all symlinking.")
                         printed_symlink_error = True
-            if os.path.isfile(outname):
-                try:
-                    depfixer.fix_rpath(outname, install_rpath, final_path,
-                                       install_name_mappings, verbose=False)
-                except SystemExit as e:
-                    if isinstance(e.code, int) and e.code == 0:
-                        pass
-                    else:
-                        raise
 
 def run(args):
     parser = buildparser()
