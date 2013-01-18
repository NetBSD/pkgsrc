$NetBSD: patch-build__tools_util.py,v 1.1 2013/01/18 11:36:40 ryoon Exp $

--- build_tools/util.py.orig	2012-08-31 05:37:06.000000000 +0000
+++ build_tools/util.py
@@ -56,6 +56,10 @@ def IsLinux():
   """Returns true if the platform is Linux."""
   return os.name == 'posix' and os.uname()[0] == 'Linux'
 
+def IsNetBSD():
+  """Returns true if the platform is Linux."""
+  return os.name == 'posix' and os.uname()[0] == 'NetBSD'
+
 
 def GetNumberOfProcessors():
   """Returns the number of CPU cores available.
