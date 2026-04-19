$NetBSD: patch-mesonbuild_modules_pkgconfig.py,v 1.10 2026/04/19 17:14:21 wiz Exp $

Revert https://github.com/mesonbuild/meson/commit/aba8792 that introduced
a condition to match FreeBSD path norm for pkg-config files.

Also undo haiku-specific change.

--- mesonbuild/modules/pkgconfig.py.orig	2026-04-13 14:03:15.000000000 +0000
+++ mesonbuild/modules/pkgconfig.py
@@ -778,10 +778,10 @@ class PkgConfigModule(NewExtensionModule):
             pkgroot_name = pkgroot.optname
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
