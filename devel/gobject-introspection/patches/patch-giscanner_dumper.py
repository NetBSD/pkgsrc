$NetBSD: patch-giscanner_dumper.py,v 1.2 2013/05/15 19:17:59 adam Exp $

Don't treat 'clang' as Visual C++ compiler.

--- giscanner/dumper.py.orig	2013-05-15 15:30:07.000000000 +0000
+++ giscanner/dumper.py
@@ -86,11 +86,6 @@ class DumpCompiler(object):
         self._linker_cmd = os.environ.get('CC', self._compiler_cmd)
         self._pkgconfig_cmd = os.environ.get('PKG_CONFIG', 'pkg-config')
         self._pkgconfig_msvc_flags = ''
-        # Enable the --msvc-syntax pkg-config flag when
-        # the Microsoft compiler is used
-        # (This is the other way to check whether Visual C++ is used subsequently)
-        if 'cl' in self._compiler_cmd:
-            self._pkgconfig_msvc_flags = '--msvc-syntax'
         self._uninst_srcdir = os.environ.get(
             'UNINSTALLED_INTROSPECTION_SRCDIR')
         self._packages = ['gio-2.0 gmodule-2.0']
