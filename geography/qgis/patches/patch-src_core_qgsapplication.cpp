$NetBSD: patch-src_core_qgsapplication.cpp,v 1.2 2016/02/02 04:33:58 dbj Exp $

Only assume we are running from a Mac OS application bundle
if the binary is in a directory ending in "/Contents/MacOS"

--- src/core/qgsapplication.cpp.orig	2016-01-15 12:00:55.000000000 +0000
+++ src/core/qgsapplication.cpp
@@ -159,8 +159,18 @@ void QgsApplication::init( QString custo
     char *prefixPath = getenv( "QGIS_PREFIX_PATH" );
     if ( !prefixPath )
     {
-#if defined(Q_OS_MACX) || defined(Q_OS_WIN)
+#if defined(Q_OS_WIN)
       setPrefixPath( applicationDirPath(), true );
+#elif defined(Q_OS_MACX)
+      QString myPrefix = applicationDirPath();
+      if ( myPrefix.endsWith( "/Contents/MacOS" ) ) {
+        setPrefixPath( myPrefix, true );
+      } else {
+        QDir myDir( applicationDirPath() );
+        myDir.cdUp();
+        myPrefix = myDir.absolutePath();
+        setPrefixPath( myPrefix, true );
+      }
 #elif defined(ANDROID)
       // this is  "/data/data/org.qgis.qgis" in android
       QDir myDir( QDir::homePath() );
@@ -577,7 +587,12 @@ QString QgsApplication::helpAppPath()
 {
   QString helpAppPath;
 #ifdef Q_OS_MACX
-  helpAppPath = applicationDirPath() + "/bin/qgis_help.app/Contents/MacOS";
+  helpAppPath = applicationDirPath();
+  if ( helpAppPath.endsWith( "/Contents/MacOS" ) ) {
+    helpAppPath += "/bin/qgis_help.app/Contents/MacOS";
+  } else {
+    helpAppPath = libexecPath();
+  }
 #else
   helpAppPath = libexecPath();
 #endif
