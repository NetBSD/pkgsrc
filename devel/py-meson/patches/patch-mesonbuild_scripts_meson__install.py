$NetBSD: patch-mesonbuild_scripts_meson__install.py,v 1.1 2018/02/25 20:27:41 wiz Exp $

This is an incorrect fix to the problem that meson strips out all rpaths.
For a longer discussion, see https://github.com/mesonbuild/meson/issues/314

--- mesonbuild/scripts/meson_install.py.orig	2018-02-20 21:48:57.000000000 +0000
+++ mesonbuild/scripts/meson_install.py
@@ -353,7 +353,6 @@ def install_targets(d):
         if is_elf_platform() and os.path.isfile(outname):
             try:
                 e = depfixer.Elf(outname, False)
-                e.fix_rpath(install_rpath)
             except SystemExit as e:
                 if isinstance(e.code, int) and e.code == 0:
                     pass
