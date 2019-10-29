$NetBSD: patch-src_core_qgsapplication.cpp,v 1.3 2019/10/29 19:30:11 bouyer Exp $

Only assume we are running from a Mac OS application bundle
if the binary is in a directory ending in "/Contents/MacOS"

--- src/core/qgsapplication.cpp.orig	2019-10-25 14:03:26.000000000 +0200
+++ src/core/qgsapplication.cpp	2019-10-25 22:58:01.706800411 +0200
@@ -233,8 +233,18 @@
     {
       if ( ABISYM( mPrefixPath ).isNull() )
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
