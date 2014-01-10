$NetBSD: patch-src_qt_YabauseThread.cpp,v 1.1 2014/01/10 20:02:56 joerg Exp $

--- src/qt/YabauseThread.cpp.orig	2014-01-10 11:41:07.000000000 +0000
+++ src/qt/YabauseThread.cpp
@@ -29,6 +29,7 @@
 #include <QDateTime>
 #include <QStringList>
 #include <QDebug>
+#include <time.h>
 
 YabauseThread::YabauseThread( QObject* o )
 	: QObject( o )
