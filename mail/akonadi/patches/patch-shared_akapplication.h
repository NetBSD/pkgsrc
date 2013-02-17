$NetBSD: patch-shared_akapplication.h,v 1.1 2013/02/17 09:14:44 markd Exp $

Work around moc inability to parse a boost macro

--- shared/akapplication.h.orig	2012-03-31 12:28:05.000000000 +0000
+++ shared/akapplication.h
@@ -23,8 +23,10 @@
 #include <QtCore/QObject>
 
 #ifndef _WIN32_WCE
+#ifndef Q_MOC_RUN
 #include <boost/program_options.hpp>
 #endif
+#endif
 
 class QCoreApplication;
 class QApplication;
