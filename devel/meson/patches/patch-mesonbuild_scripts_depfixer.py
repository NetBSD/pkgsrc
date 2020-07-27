$NetBSD: patch-mesonbuild_scripts_depfixer.py,v 1.2 2020/07/27 16:08:13 adam Exp $

Do not touch rpath for ELF.

--- mesonbuild/scripts/depfixer.py.orig	2020-06-29 17:00:15.000000000 +0000
+++ mesonbuild/scripts/depfixer.py
@@ -457,8 +457,6 @@ def fix_rpath(fname, rpath_dirs_to_remov
         if fname.endswith('.jar'):
             fix_jar(fname)
             return
-        fix_elf(fname, rpath_dirs_to_remove, new_rpath, verbose)
-        return
     except SystemExit as e:
         if isinstance(e.code, int) and e.code == 0:
             pass
