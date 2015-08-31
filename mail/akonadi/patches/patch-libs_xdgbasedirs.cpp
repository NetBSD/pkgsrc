$NetBSD: patch-libs_xdgbasedirs.cpp,v 1.1 2015/08/31 16:16:31 jperkin Exp $

Disable MacOS bundle support, install in the normal place.

--- libs/xdgbasedirs.cpp.orig	2014-08-10 10:38:58.000000000 +0000
+++ libs/xdgbasedirs.cpp
@@ -38,7 +38,7 @@ static QStringList alternateExecPaths( c
 
 #if defined(Q_OS_WIN) //krazy:exclude=cpp
   pathList << path + QLatin1String( ".exe" );
-#elif defined(Q_OS_MAC) //krazy:exclude=cpp
+#elif defined(notQ_OS_MAC) //krazy:exclude=cpp
   pathList << path + QLatin1String( ".app/Contents/MacOS/" ) + path.section( QLatin1Char( '/' ), -1 );
 #endif
 
@@ -247,7 +247,7 @@ QString XdgBaseDirs::findExecutableFile(
 
     executableDirs += searchPath;
 
-#if defined(Q_OS_MAC) //krazy:exclude=cpp
+#if defined(notQ_OS_MAC) //krazy:exclude=cpp
     executableDirs += QLatin1String( AKONADIBUNDLEPATH );
 #endif
     qWarning() << "search paths: " << executableDirs;
