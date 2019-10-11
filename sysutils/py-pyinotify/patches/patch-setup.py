$NetBSD: patch-setup.py,v 1.3 2019/10/11 14:38:56 wiz Exp $

Add NetBSD.

--- setup.py.orig	2015-06-04 15:28:48.000000000 +0000
+++ setup.py
@@ -3,7 +3,7 @@
 # Set True to force compile native C-coded extension providing direct access
 # to inotify's syscalls. If set to False this extension will only be compiled
 # if no inotify interface from ctypes is found.
-compile_ext_mod = False
+compile_ext_mod = True
 
 # import statements
 import os
@@ -24,10 +24,6 @@ if sys.version_info < (2, 4):
     sys.stderr.write('This module requires at least Python 2.4\n')
     sys.exit(1)
 
-# check linux platform
-if not platform.startswith('linux') and not platform.startswith('freebsd'):
-    sys.stderr.write("inotify is not available on %s\n" % platform)
-    sys.exit(1)
 
 
 classif = [
@@ -71,7 +67,7 @@ def should_compile_ext_mod():
         return True
 
     try_libc_name = 'c'
-    if platform.startswith('freebsd'):
+    if platform.startswith('freebsd') or platform.startswith('netbsd'):
         try_libc_name = 'inotify'
 
     libc_name = None
