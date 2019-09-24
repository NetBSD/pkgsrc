$NetBSD: patch-setup.py,v 1.2 2019/09/24 09:04:08 adam Exp $

Add NetBSD.

--- setup.py.orig	2015-06-04 15:28:48.000000000 +0000
+++ setup.py
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
