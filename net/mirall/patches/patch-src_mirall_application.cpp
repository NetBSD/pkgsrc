$NetBSD: patch-src_mirall_application.cpp,v 1.3 2014/12/21 20:19:50 ryoon Exp $

--- src/mirall/application.cpp.orig	2013-10-21 12:05:25.000000000 +0000
+++ src/mirall/application.cpp
@@ -81,7 +81,7 @@ static const char optionsC[] =
 
 QString applicationTrPath()
 {
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_NETBSD)
     return QString::fromLatin1(DATADIR"/"APPLICATION_EXECUTABLE"/i18n/");
 #endif
 #ifdef Q_OS_MAC
