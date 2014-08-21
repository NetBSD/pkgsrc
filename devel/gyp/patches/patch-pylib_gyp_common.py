$NetBSD: patch-pylib_gyp_common.py,v 1.3 2014/08/21 14:49:43 he Exp $

* Add NetBSD support

--- pylib/gyp/common.py.orig	2014-07-14 14:19:49.000000000 +0000
+++ pylib/gyp/common.py
@@ -420,6 +420,8 @@ def GetFlavor(params):
     return 'openbsd'
   if sys.platform.startswith('aix'):
     return 'aix'
+  if sys.platform.startswith('netbsd'):
+    return 'netbsd'
 
   return 'linux'
 
@@ -432,6 +434,7 @@ def CopyTool(flavor, out_path):
   prefix = {
       'aix': 'flock',
       'solaris': 'flock',
+      'netbsd': 'flock',
       'mac': 'mac',
       'win': 'win'
       }.get(flavor, None)
