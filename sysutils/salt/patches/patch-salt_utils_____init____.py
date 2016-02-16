$NetBSD: patch-salt_utils_____init____.py,v 1.1 2016/02/16 01:52:34 khorben Exp $

Use sockstat(1) on NetBSD

--- salt/utils/__init__.py.orig	2016-02-01 19:40:31.000000000 +0000
+++ salt/utils/__init__.py
@@ -1664,6 +1664,14 @@ def is_freebsd():
 
 
 @real_memoize
+def is_netbsd():
+    '''
+    Simple function to return if host is NetBSD or not
+    '''
+    return sys.platform.startswith('netbsd')
+
+
+@real_memoize
 def is_openbsd():
     '''
     Simple function to return if host is OpenBSD or not
