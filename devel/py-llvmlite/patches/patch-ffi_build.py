$NetBSD: patch-ffi_build.py,v 1.2 2018/08/07 10:46:42 adam Exp $

Add NetBSD support

--- ffi/build.py.orig	2018-07-10 14:46:02.000000000 +0000
+++ ffi/build.py
@@ -143,6 +143,8 @@ def main():
         main_posix('linux', '.so')
     elif sys.platform.startswith(('freebsd','openbsd')):
         main_posix('freebsd', '.so')
+    elif sys.platform.startswith('netbsd'):
+        main_posix('netbsd', '.so')
     elif sys.platform == 'darwin':
         main_posix('osx', '.dylib')
     else:
