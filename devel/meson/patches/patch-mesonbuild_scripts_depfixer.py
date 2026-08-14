$NetBSD: patch-mesonbuild_scripts_depfixer.py,v 1.6 2026/08/14 13:56:41 adam Exp $

Do not remove rpaths for ELF, except for Darwin.

--- mesonbuild/scripts/depfixer.py.orig	2026-08-10 20:56:48.000000000 +0000
+++ mesonbuild/scripts/depfixer.py
@@ -824,7 +824,7 @@ def fix_rpath(fname: str, rpath_dirs_to_
             return
         if system == 'aix':
             fix_aix(fname, rpath_dirs_to_remove, new_rpath, verbose)
-        else:
+        elif system == 'darwin':
             fix_elf(fname, rpath_dirs_to_remove, new_rpath, verbose)
         return
     except SystemExit as e:
