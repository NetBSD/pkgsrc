$NetBSD: patch-ffi_build.py,v 1.9 2024/08/27 10:30:35 wiz Exp $

Add NetBSD support.

--- ffi/build.py.orig	2020-05-08 14:22:24.000000000 +0000
+++ ffi/build.py
@@ -182,6 +182,8 @@ def main():
         main_posix('linux', '.so')
     elif sys.platform.startswith(('freebsd','openbsd')):
         main_posix('freebsd', '.so')
+    elif sys.platform.startswith('netbsd'):
+        main_posix('netbsd', '.so')
     elif sys.platform == 'darwin':
         main_posix('osx', '.dylib')
     else:
