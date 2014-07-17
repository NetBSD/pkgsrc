$NetBSD: patch-Source_kwsys_SystemTools.cxx,v 1.1 2014/07/17 13:44:28 ryoon Exp $

* SCO OpenServer 5.0.7/3.2's command has 711 permission.

--- Source/kwsys/SystemTools.cxx.orig	2014-01-16 17:15:08.000000000 +0000
+++ Source/kwsys/SystemTools.cxx
@@ -1071,7 +1071,12 @@ bool SystemTools::FileExists(const char*
 #elif defined(_WIN32)
   return WindowsFileExists(filename);
 #else
+// SCO OpenServer 5.0.7/3.2's command has 711 permission.
+#  if defined(_SCO_DS)
+  return access(filename, F_OK) == 0;
+#  else
   return access(filename, R_OK) == 0;
+#  endif
 #endif
 }
 
