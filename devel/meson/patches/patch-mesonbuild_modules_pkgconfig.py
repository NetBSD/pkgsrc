$NetBSD: patch-mesonbuild_modules_pkgconfig.py,v 1.1 2020/04/23 07:00:09 triaxx Exp $

* Revert https://github.com/mesonbuild/meson/commit/aba8792 that introduced
  a condition to match FreeBSD path norm for pkg-config files.

--- mesonbuild/modules/pkgconfig.py.orig	2020-03-23 17:22:09.000000000 +0000
+++ mesonbuild/modules/pkgconfig.py
@@ -496,10 +496,7 @@ class PkgConfigModule(ExtensionModule):
         pcfile = filebase + '.pc'
         pkgroot = kwargs.get('install_dir', default_install_dir)
         if pkgroot is None:
-            if mesonlib.is_freebsd():
-                pkgroot = os.path.join(state.environment.coredata.get_builtin_option('prefix'), 'libdata', 'pkgconfig')
-            else:
-                pkgroot = os.path.join(state.environment.coredata.get_builtin_option('libdir'), 'pkgconfig')
+            pkgroot = os.path.join(state.environment.coredata.get_builtin_option('libdir'), 'pkgconfig')
         if not isinstance(pkgroot, str):
             raise mesonlib.MesonException('Install_dir must be a string.')
         self.generate_pkgconfig_file(state, deps, subdirs, name, description, url,
