$NetBSD: patch-src_core_proj_qgscoordinatereferencesystemutils.cpp,v 1.1 2025/05/02 17:05:07 gdt Exp $

Add a translation for spilhaus, newly in proj 9.6.0.

Not filed upstream because 3.34 is no longer maintained, surely upstream
is aware, and thus this must be fixed in 3.40.

--- src/core/proj/qgscoordinatereferencesystemutils.cpp.orig	2025-05-02 13:15:20.754684358 +0000
+++ src/core/proj/qgscoordinatereferencesystemutils.cpp
@@ -482,5 +482,7 @@ QString QgsCoordinateReferenceSystemUtil
     return QObject::tr( "Winkel Tripel" );
   if ( projection == QLatin1String( "gstmerc" ) )
     return QObject::tr( "Gauss-Schreiber" );
+  if ( projection == QLatin1String( "spilhaus" ) )
+    return QObject::tr( "Spilhaus" );
   return QString();
 }
