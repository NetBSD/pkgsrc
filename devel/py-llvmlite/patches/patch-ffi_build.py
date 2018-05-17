$NetBSD: patch-ffi_build.py,v 1.1 2018/05/17 15:47:46 minskim Exp $

Add NetBSD support

--- ffi/build.py.orig	2016-08-24 14:49:54.000000000 +0000
+++ ffi/build.py
@@ -142,6 +142,8 @@ def main():
         main_posix('linux', '.so')
     elif sys.platform.startswith('freebsd'):
         main_posix('freebsd', '.so')
+    elif sys.platform.startswith('netbsd'):
+        main_posix('netbsd', '.so')
     elif sys.platform == 'darwin':
         main_posix('osx', '.dylib')
     else:
