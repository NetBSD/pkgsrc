$NetBSD: patch-mesonbuild_scripts_depfixer.py,v 1.4 2022/07/13 03:57:22 triaxx Exp $

Do not touch rpath for ELF.

--- mesonbuild/scripts/depfixer.py.orig	2020-09-17 22:00:44.000000000 +0000
+++ mesonbuild/scripts/depfixer.py
@@ -482,8 +482,6 @@ def fix_rpath(fname: str, rpath_dirs_to_
             return
         if isinstance(new_rpath, str):
             new_rpath = new_rpath.encode('utf8')
-        fix_elf(fname, rpath_dirs_to_remove, new_rpath, verbose)
-        return
     except SystemExit as e:
         if isinstance(e.code, int) and e.code == 0:
             pass
