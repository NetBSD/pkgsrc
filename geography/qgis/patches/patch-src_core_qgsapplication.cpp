$NetBSD: patch-src_core_qgsapplication.cpp,v 1.1 2012/02/26 23:19:02 adam Exp $

Use UNIX prefix path on Mac OS X.

--- src/core/qgsapplication.cpp.orig	2012-02-26 22:09:01.000000000 +0000
+++ src/core/qgsapplication.cpp
@@ -60,7 +60,7 @@ QString QgsApplication::mConfigPath = QD
 QgsApplication::QgsApplication( int & argc, char ** argv, bool GUIenabled, QString customConfigPath )
     : QApplication( argc, argv, GUIenabled )
 {
-#if defined(Q_WS_MACX) || defined(Q_WS_WIN32) || defined(WIN32)
+#if defined(Q_WS_WIN32) || defined(WIN32)
   setPrefixPath( applicationDirPath(), true );
 #else
   QDir myDir( applicationDirPath() );
