$NetBSD: patch-mesonbuild_scripts_depfixer.py,v 1.1 2019/10/04 14:06:19 prlw1 Exp $

Do not touch rpath for ELF.

--- mesonbuild/scripts/depfixer.py.orig	2019-06-06 05:17:20.000000000 +0000
+++ mesonbuild/scripts/depfixer.py
@@ -439,8 +439,6 @@ def fix_rpath(fname, new_rpath, final_pa
         if fname.endswith('.jar'):
             fix_jar(fname)
             return
-        fix_elf(fname, new_rpath, verbose)
-        return
     except SystemExit as e:
         if isinstance(e.code, int) and e.code == 0:
             pass
