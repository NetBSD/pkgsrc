$NetBSD: patch-setup.py,v 1.3 2017/02/02 11:53:58 fhajny Exp $

Let compiler decide what's best.

--- setup.py.orig	2016-11-22 12:41:00.000000000 +0000
+++ setup.py
@@ -203,12 +203,6 @@ def settings_from_prefix(prefix=None, bu
         if sys.platform.startswith('freebsd'):
             settings['libraries'].append('pthread')
 
-        if sys.platform.startswith('sunos'):
-          if platform.architecture()[0] == '32bit':
-            settings['extra_link_args'] += ['-m32']
-          else:
-            settings['extra_link_args'] += ['-m64']
-
         if prefix:
             settings['libraries'].append('zmq')
 
