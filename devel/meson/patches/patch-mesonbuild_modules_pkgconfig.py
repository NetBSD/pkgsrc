$NetBSD: patch-mesonbuild_modules_pkgconfig.py,v 1.6 2022/11/13 09:57:24 adam Exp $

Revert https://github.com/mesonbuild/meson/commit/aba8792 that introduced
a condition to match FreeBSD path norm for pkg-config files.

--- mesonbuild/modules/pkgconfig.py.orig	2022-10-24 19:25:24.000000000 +0000
+++ mesonbuild/modules/pkgconfig.py
@@ -696,7 +696,7 @@ class PkgConfigModule(NewExtensionModule
         pcfile = filebase + '.pc'
         pkgroot = pkgroot_name = kwargs['install_dir'] or default_install_dir
         if pkgroot is None:
-            if mesonlib.is_freebsd():
+            if False:
                 pkgroot = os.path.join(_as_str(state.environment.coredata.get_option(mesonlib.OptionKey('prefix'))), 'libdata', 'pkgconfig')
                 pkgroot_name = os.path.join('{prefix}', 'libdata', 'pkgconfig')
             else:
