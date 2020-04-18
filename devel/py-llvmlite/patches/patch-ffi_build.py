$NetBSD: patch-ffi_build.py,v 1.6 2020/04/18 08:11:53 adam Exp $

Allow building with LLVM 10.0.x and 9.0.x.
Add NetBSD support.

--- ffi/build.py.orig	2020-04-17 14:49:06.000000000 +0000
+++ ffi/build.py
@@ -110,7 +110,7 @@ def main_posix(kind, library_ext):
 
     out = out.decode('latin1')
     print(out)
-    if not (out.startswith('8.0.') or out.startswith('7.0.')
+    if not (out.startswith('10.0.') or out.startswith('9.0.') or out.startswith('8.0.') or out.startswith('7.0.')
             or out.startswith('7.1.')):
         msg = (
             "Building llvmlite requires LLVM 7.0.x, 7.1.x or 8.0.x, got {!r}. "
@@ -158,6 +158,8 @@ def main():
         main_posix('linux', '.so')
     elif sys.platform.startswith(('freebsd','openbsd')):
         main_posix('freebsd', '.so')
+    elif sys.platform.startswith('netbsd'):
+        main_posix('netbsd', '.so')
     elif sys.platform == 'darwin':
         main_posix('osx', '.dylib')
     else:
