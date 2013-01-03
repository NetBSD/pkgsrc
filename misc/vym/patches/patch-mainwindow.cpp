$NetBSD: patch-mainwindow.cpp,v 1.1 2013/01/03 15:44:19 ryoon Exp $

--- mainwindow.cpp.orig	2012-07-04 13:28:11.000000000 +0000
+++ mainwindow.cpp
@@ -228,7 +228,7 @@ Main::Main(QWidget* parent, Qt::WFlags f
 
 	// application to open URLs
 	p="/mainwindow/readerURL";
-	#if defined(Q_OS_LINUX)
+	#if defined(Q_OS_UNIX)
 	    s=settings.value (p,"xdg-open").toString();
 	#else
 	    #if defined(Q_OS_MACX)
@@ -249,7 +249,7 @@ Main::Main(QWidget* parent, Qt::WFlags f
 
 	// application to open PDFs
 	p="/mainwindow/readerPDF";
-	#if defined(Q_OS_LINUX)
+	#if defined(Q_OS_UNIX)
 	    s=settings.value (p,"xdg-open").toString();
 	#else
 	    #if defined(Q_OS_MACX)
