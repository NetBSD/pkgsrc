$NetBSD: patch-mesonbuild_minstall.py,v 1.2 2019/03/05 16:30:18 prlw1 Exp $

Don't touch rpath.

--- mesonbuild/minstall.py.orig	2019-01-23 16:46:09.000000000 +0000
+++ mesonbuild/minstall.py
@@ -476,15 +476,6 @@ class Installer:
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
 
 def run(opts):
     datafilename = 'meson-private/install.dat'
