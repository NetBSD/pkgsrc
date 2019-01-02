$NetBSD: patch-ffi_build.py,v 1.4 2019/01/02 15:42:17 adam Exp $

Add NetBSD support.

--- ffi/build.py.orig	2018-07-10 14:46:02.000000000 +0000
+++ ffi/build.py
@@ -157,6 +157,8 @@ def main():
         main_posix('linux', '.so')
     elif sys.platform.startswith(('freebsd','openbsd')):
         main_posix('freebsd', '.so')
+    elif sys.platform.startswith('netbsd'):
+        main_posix('netbsd', '.so')
     elif sys.platform == 'darwin':
         main_posix('osx', '.dylib')
     else:
