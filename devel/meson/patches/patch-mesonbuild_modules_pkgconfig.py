$NetBSD: patch-mesonbuild_modules_pkgconfig.py,v 1.3 2021/09/27 18:50:06 adam Exp $

Revert https://github.com/mesonbuild/meson/commit/aba8792 that introduced
a condition to match FreeBSD path norm for pkg-config files.

--- mesonbuild/modules/pkgconfig.py.orig	2021-08-18 11:22:33.000000000 +0000
+++ mesonbuild/modules/pkgconfig.py
@@ -549,10 +549,7 @@ class PkgConfigModule(ExtensionModule):
         pcfile = filebase + '.pc'
         pkgroot = kwargs.get('install_dir', default_install_dir)
         if pkgroot is None:
-            if mesonlib.is_freebsd():
-                pkgroot = os.path.join(state.environment.coredata.get_option(mesonlib.OptionKey('prefix')), 'libdata', 'pkgconfig')
-            else:
-                pkgroot = os.path.join(state.environment.coredata.get_option(mesonlib.OptionKey('libdir')), 'pkgconfig')
+            pkgroot = os.path.join(state.environment.coredata.get_option(mesonlib.OptionKey('libdir')), 'pkgconfig')
         if not isinstance(pkgroot, str):
             raise mesonlib.MesonException('Install_dir must be a string.')
         self._generate_pkgconfig_file(state, deps, subdirs, name, description, url,
