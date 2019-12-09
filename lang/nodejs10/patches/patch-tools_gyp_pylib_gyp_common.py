$NetBSD: patch-tools_gyp_pylib_gyp_common.py,v 1.1 2019/12/09 20:05:40 adam Exp $

Add support for DragonFly.
--- tools/gyp/pylib/gyp/common.py.orig	2017-05-03 02:00:16.000000000 +0000
+++ tools/gyp/pylib/gyp/common.py
@@ -427,6 +427,8 @@ def GetFlavor(params):
     return 'openbsd'
   if sys.platform.startswith('netbsd'):
     return 'netbsd'
+  if sys.platform.startswith('dragonflybsd'):
+    return 'dragonflybsd'
   if sys.platform.startswith('aix'):
     return 'aix'
 
