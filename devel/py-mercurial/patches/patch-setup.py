$NetBSD: patch-setup.py,v 1.3 2025/09/23 00:24:57 joerg Exp $

Skip existence check for Python.h so this can be cross-compiled.

The pkgsrc toolchain wrapper will interpose a sysroot to resolve the
.h file reference.

--- setup.py.orig	2023-05-04 12:17:18.000000000 +0000
+++ setup.py
@@ -485,13 +485,6 @@ class hgbuildpy(build_py):
 
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
         rust = self.distribution.rust
