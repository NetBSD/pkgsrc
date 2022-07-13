$NetBSD: patch-mesonbuild_modules_pkgconfig.py,v 1.5 2022/07/13 03:57:22 triaxx Exp $

Revert https://github.com/mesonbuild/meson/commit/aba8792 that introduced
a condition to match FreeBSD path norm for pkg-config files.

--- mesonbuild/modules/pkgconfig.py.orig	2022-06-19 19:10:14.000000000 +0000
+++ mesonbuild/modules/pkgconfig.py
@@ -593,12 +593,8 @@ class PkgConfigModule(ExtensionModule):
         pcfile = filebase + '.pc'
         pkgroot = pkgroot_name = kwargs.get('install_dir', default_install_dir)
         if pkgroot is None:
-            if mesonlib.is_freebsd():
-                pkgroot = os.path.join(state.environment.coredata.get_option(mesonlib.OptionKey('prefix')), 'libdata', 'pkgconfig')
-                pkgroot_name = os.path.join('{prefix}', 'libdata', 'pkgconfig')
-            else:
-                pkgroot = os.path.join(state.environment.coredata.get_option(mesonlib.OptionKey('libdir')), 'pkgconfig')
-                pkgroot_name = os.path.join('{libdir}', 'pkgconfig')
+            pkgroot = os.path.join(state.environment.coredata.get_option(mesonlib.OptionKey('libdir')), 'pkgconfig')
+            pkgroot_name = os.path.join('{libdir}', 'pkgconfig')
         if not isinstance(pkgroot, str):
             raise mesonlib.MesonException('Install_dir must be a string.')
         relocatable = state.get_option('relocatable', module='pkgconfig')
