$NetBSD: patch-src_3rdparty_opennurbs_opennurbs__defines.cpp,v 1.1 2025/08/19 12:52:17 plunky Exp $

fcloseall() may not be available (CloseAllFiles is not used by QCAD anyway)

--- src/3rdparty/opennurbs/opennurbs_defines.cpp.orig	2025-06-29 15:24:08.450418459 +0000
+++ src/3rdparty/opennurbs/opennurbs_defines.cpp
@@ -499,7 +499,7 @@ int ON::CloseAllFiles()
   //fcloseall is not supported on mac/ios or android
   return EOF;
 #else
-  return fcloseall();
+  return EOF;
 #endif
 }
 
