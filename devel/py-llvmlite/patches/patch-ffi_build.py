$NetBSD: patch-ffi_build.py,v 1.3 2018/12/09 20:22:55 adam Exp $

Allow newer LLVM.
Add NetBSD support.

--- ffi/build.py.orig	2018-07-10 14:46:02.000000000 +0000
+++ ffi/build.py
@@ -109,7 +109,7 @@ def main_posix(kind, library_ext):
 
     out = out.decode('latin1')
     print(out)
-    if not out.startswith('6.0.'):
+    if False:
         msg = (
             "Building llvmlite requires LLVM 6.0.x. Be sure to "
             "set LLVM_CONFIG to the right executable path.\n"
@@ -157,6 +157,8 @@ def main():
         main_posix('linux', '.so')
     elif sys.platform.startswith(('freebsd','openbsd')):
         main_posix('freebsd', '.so')
+    elif sys.platform.startswith('netbsd'):
+        main_posix('netbsd', '.so')
     elif sys.platform == 'darwin':
         main_posix('osx', '.dylib')
     else:
