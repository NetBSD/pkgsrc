$NetBSD: patch-Source_kwsys_SystemTools.cxx,v 1.2 2014/08/10 10:02:51 adam Exp $

* SCO OpenServer 5.0.7/3.2's command has 711 permission.

--- Source/kwsys/SystemTools.cxx.orig	2014-07-31 15:03:57.000000000 +0000
+++ Source/kwsys/SystemTools.cxx
@@ -1081,7 +1081,12 @@ bool SystemTools::FileExists(const char*
   return (GetFileAttributesW(Encoding::ToWide(filename).c_str())
           != INVALID_FILE_ATTRIBUTES);
 #else
+// SCO OpenServer 5.0.7/3.2's command has 711 permission.
+#  if defined(_SCO_DS)
+  return access(filename, F_OK) == 0;
+#  else
   return access(filename, R_OK) == 0;
+#  endif
 #endif
 }
 
