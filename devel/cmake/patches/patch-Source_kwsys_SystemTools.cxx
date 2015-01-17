$NetBSD: patch-Source_kwsys_SystemTools.cxx,v 1.3 2015/01/17 13:29:55 adam Exp $

* SCO OpenServer 5.0.7/3.2's command has 711 permission.

--- Source/kwsys/SystemTools.cxx.orig	2014-12-15 20:07:43.000000000 +0000
+++ Source/kwsys/SystemTools.cxx
@@ -1120,8 +1120,13 @@ bool SystemTools::FileExists(const kwsys
             SystemTools::ConvertToWindowsExtendedPath(filename).c_str())
           != INVALID_FILE_ATTRIBUTES);
 #else
+// SCO OpenServer 5.0.7/3.2's command has 711 permission.
+#if defined(_SCO_DS)
+  return access(filename.c_str(), F_OK) == 0;
+#else
   return access(filename.c_str(), R_OK) == 0;
 #endif
+#endif
 }
 
 //----------------------------------------------------------------------------
