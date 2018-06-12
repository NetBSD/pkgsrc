$NetBSD: patch-setup.py,v 1.1 2018/06/12 01:00:56 youri Exp $

Add NetBSD.

--- setup.py.orig	2015-06-04 15:28:48.000000000 +0000
+++ setup.py
@@ -25,7 +25,7 @@ if sys.version_info < (2, 4):
     sys.exit(1)
 
 # check linux platform
-if not platform.startswith('linux') and not platform.startswith('freebsd'):
+if not platform.startswith('linux') and not platform.startswith('freebsd') and not platform.startswith('netbsd'):
     sys.stderr.write("inotify is not available on %s\n" % platform)
     sys.exit(1)
 
@@ -71,7 +71,7 @@ def should_compile_ext_mod():
         return True
 
     try_libc_name = 'c'
-    if platform.startswith('freebsd'):
+    if platform.startswith('freebsd') or platform.startswith('netbsd'):
         try_libc_name = 'inotify'
 
     libc_name = None
