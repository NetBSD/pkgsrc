$NetBSD: patch-src_qt_YabauseThread.cpp,v 1.2 2015/02/13 05:45:10 snj Exp $

Add missing include for struct tm.

--- src/qt/YabauseThread.cpp.orig	2014-11-12 09:48:47.000000000 -0800
+++ src/qt/YabauseThread.cpp	2015-02-08 22:53:26.000000000 -0800
@@ -29,6 +29,7 @@
 #include <QDateTime>
 #include <QStringList>
 #include <QDebug>
+#include <time.h>
 
 YabauseThread::YabauseThread( QObject* o )
 	: QObject( o )
