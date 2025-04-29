$NetBSD: patch-mesonbuild_modules_pkgconfig.py,v 1.9 2025/04/29 10:46:11 wiz Exp $

Revert https://github.com/mesonbuild/meson/commit/aba8792 that introduced
a condition to match FreeBSD path norm for pkg-config files.

Also undo haiku-specific change.

--- mesonbuild/modules/pkgconfig.py.orig	2025-04-28 15:36:57.000000000 +0000
+++ mesonbuild/modules/pkgconfig.py
@@ -702,10 +702,10 @@ class PkgConfigModule(NewExtensionModule
         pkgroot = pkgroot_name = kwargs['install_dir'] or default_install_dir
         if pkgroot is None:
             m = state.environment.machines.host
-            if m.is_freebsd():
+            if False:
                 pkgroot = os.path.join(_as_str(state.environment.coredata.optstore.get_value_for(OptionKey('prefix'))), 'libdata', 'pkgconfig')
                 pkgroot_name = os.path.join('{prefix}', 'libdata', 'pkgconfig')
-            elif m.is_haiku():
+            elif False:
                 pkgroot = os.path.join(_as_str(state.environment.coredata.optstore.get_value_for(OptionKey('prefix'))), 'develop', 'lib', 'pkgconfig')
                 pkgroot_name = os.path.join('{prefix}', 'develop', 'lib', 'pkgconfig')
             else:
