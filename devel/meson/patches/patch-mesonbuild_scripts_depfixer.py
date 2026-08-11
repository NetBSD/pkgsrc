$NetBSD: patch-mesonbuild_scripts_depfixer.py,v 1.5 2026/08/11 11:43:05 wiz Exp $

Do not remove rpaths for ELF.

--- mesonbuild/scripts/depfixer.py.orig	2026-08-11 11:28:11.685123152 +0000
+++ mesonbuild/scripts/depfixer.py
@@ -824,8 +824,6 @@ def fix_rpath(fname: str, rpath_dirs_to_remove: T.Set[
             return
         if system == 'aix':
             fix_aix(fname, rpath_dirs_to_remove, new_rpath, verbose)
-        else:
-            fix_elf(fname, rpath_dirs_to_remove, new_rpath, verbose)
         return
     except SystemExit as e:
         if isinstance(e.code, int) and e.code == 0:
