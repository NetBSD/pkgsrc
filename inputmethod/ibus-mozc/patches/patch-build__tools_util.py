$NetBSD: patch-build__tools_util.py,v 1.2 2013/04/29 09:21:24 ryoon Exp $

--- build_tools/util.py.orig	2013-03-29 04:33:44.000000000 +0000
+++ build_tools/util.py
@@ -56,6 +56,9 @@ def IsLinux():
   """Returns true if the platform is Linux."""
   return os.name == 'posix' and os.uname()[0] == 'Linux'
 
+def IsNetBSD():
+  """Returns true if the platform is Linux."""
+  return os.name == 'posix' and os.uname()[0] == 'NetBSD'
 
 def GetNumberOfProcessors():
   """Returns the number of CPU cores available.
