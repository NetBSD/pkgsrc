$NetBSD: patch-setup.py,v 1.2 2023/10/02 20:37:22 triaxx Exp $

Skip existence check for Python.h so this can be cross-compiled.

The pkgsrc toolchain wrapper will interpose a sysroot to resolve the
.h file reference.

--- setup.py.orig	2023-05-04 12:17:18.000000000 +0000
+++ setup.py
@@ -658,13 +658,6 @@ class hgbuildpy(build_py):
 
                 exts.append(osutilbuild.ffi.distutils_extension())
             self.distribution.ext_modules = exts
-        else:
-            h = os.path.join(get_python_inc(), 'Python.h')
-            if not os.path.exists(h):
-                raise SystemExit(
-                    'Python headers are required to build '
-                    'Mercurial but weren\'t found in %s' % h
-                )
 
     def run(self):
         basepath = os.path.join(self.build_lib, 'mercurial')
