$NetBSD: patch-setup.py,v 1.4 2021/11/14 20:17:08 adam Exp $

Let compiler decide what's best.

--- setup.py.orig	2021-09-16 07:32:51.000000000 +0000
+++ setup.py
@@ -282,11 +282,6 @@ def settings_from_prefix(prefix=None):
         if sys.platform.startswith('freebsd'):
             settings['libraries'].append('pthread')
 
-        if sys.platform.startswith('sunos'):
-            if platform.architecture()[0] == '32bit':
-                settings['extra_link_args'] += ['-m32']
-            else:
-                settings['extra_link_args'] += ['-m64']
 
         if prefix:
             settings['libraries'].append('zmq')
