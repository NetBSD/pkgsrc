$NetBSD: patch-src_core_qgsapplication.cpp,v 1.4 2021/03/01 00:03:35 gdt Exp $

Only assume we are running from a Mac OS application bundle
if the binary is in a directory ending in "/Contents/MacOS"

--- src/core/qgsapplication.cpp.orig	2021-02-19 12:09:21.000000000 +0000
+++ src/core/qgsapplication.cpp
@@ -279,8 +279,18 @@ void QgsApplication::init( QString profi
     {
       if ( sPrefixPath()->isNull() )
       {
-#if defined(Q_OS_MACX) || defined(Q_OS_WIN)
+#if defined(Q_OS_WIN)
         setPrefixPath( applicationDirPath(), true );
+#elif defined(Q_OS_MACX)
+       QString myPrefix = applicationDirPath();
+       if ( myPrefix.endsWith( "/Contents/MacOS" ) ) {
+         setPrefixPath( myPrefix, true );
+       } else {
+         QDir myDir( applicationDirPath() );
+         myDir.cdUp();
+         myPrefix = myDir.absolutePath();
+         setPrefixPath( myPrefix, true );
+       }                              
 #elif defined(ANDROID)
         // this is "/data/data/org.qgis.qgis" in android
         QDir myDir( QDir::homePath() );
