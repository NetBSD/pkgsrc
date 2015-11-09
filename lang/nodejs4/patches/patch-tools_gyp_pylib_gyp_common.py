$NetBSD: patch-tools_gyp_pylib_gyp_common.py,v 1.1 2015/11/09 20:21:51 fhajny Exp $

Add support for NetBSD and DragonFly.
--- tools/gyp/pylib/gyp/common.py.orig	2013-03-28 19:07:52.000000000 +0000
+++ tools/gyp/pylib/gyp/common.py
@@ -394,6 +394,10 @@ def GetFlavor(params):
     return 'freebsd'
   if sys.platform.startswith('openbsd'):
     return 'openbsd'
+  if sys.platform.startswith('netbsd'):
+    return 'netbsd'
+  if sys.platform.startswith('dragonflybsd'):
+    return 'dragonflybsd'
   if sys.platform.startswith('aix'):
     return 'aix'
 
