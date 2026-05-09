$NetBSD: patch-src_core_qgsogrutils.cpp,v 1.1 2026/05/09 12:01:07 gdt Exp $

--- src/core/qgsogrutils.cpp.orig	2026-04-03 12:00:51.000000000 +0000
+++ src/core/qgsogrutils.cpp
@@ -1153,7 +1153,7 @@ QgsFields QgsOgrUtils::stringToFields( c
   return fields;
 }
 
-QStringList QgsOgrUtils::cStringListToQStringList( char **stringList )
+QStringList QgsOgrUtils::cStringListToQStringList( const char *const *stringList )
 {
   if ( !stringList )
     return {};
