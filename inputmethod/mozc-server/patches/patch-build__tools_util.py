$NetBSD: patch-build__tools_util.py,v 1.2 2013/07/20 04:34:53 ryoon Exp $

--- build_tools/util.py.orig	2013-07-17 02:37:50.000000000 +0000
+++ build_tools/util.py
@@ -56,6 +56,10 @@ def IsLinux():
   """Returns true if the platform is Linux."""
   return os.name == 'posix' and os.uname()[0] == 'Linux'
 
+def IsNetBSD():
+  """Returns true if the platform is NetBSD."""
+  return os.name == 'posix' and os.uname()[0] == 'NetBSD'
+ 
 
 def GetNumberOfProcessors():
   """Returns the number of CPU cores available.
