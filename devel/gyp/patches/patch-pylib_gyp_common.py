$NetBSD: patch-pylib_gyp_common.py,v 1.2 2013/09/08 16:33:25 ryoon Exp $

* Add NetBSD support

--- pylib/gyp/common.py.orig	2013-09-06 23:07:36.000000000 +0000
+++ pylib/gyp/common.py
@@ -403,6 +403,8 @@ def GetFlavor(params):
     return 'openbsd'
   if sys.platform.startswith('aix'):
     return 'aix'
+  if sys.platform.startswith('netbsd'):
+    return 'netbsd'
 
   return 'linux'
 
