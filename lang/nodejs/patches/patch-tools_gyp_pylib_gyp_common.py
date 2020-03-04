$NetBSD: patch-tools_gyp_pylib_gyp_common.py,v 1.5 2020/03/04 18:59:39 adam Exp $

Add support for DragonFly.

--- tools/gyp/pylib/gyp/common.py.orig	2020-03-04 07:36:10.000000000 +0000
+++ tools/gyp/pylib/gyp/common.py
@@ -440,6 +440,8 @@ def GetFlavor(params):
     return 'openbsd'
   if sys.platform.startswith('netbsd'):
     return 'netbsd'
+  if sys.platform.startswith('dragonflybsd'):
+    return 'dragonflybsd'
   if sys.platform.startswith('aix'):
     return 'aix'
   if sys.platform.startswith(('os390', 'zos')):
