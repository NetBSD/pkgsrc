$NetBSD: patch-modules_gui_qt4_main__interface.hpp,v 1.1 2015/10/25 11:00:18 wiz Exp $

Qt's MOC doesn't handle int64_t, so introduce a meaningful type name
so that slot/signal/connection macros work properly.

--- modules/gui/qt4/main_interface.hpp.orig	2014-12-17 16:53:33.000000000 +0000
+++ modules/gui/qt4/main_interface.hpp
@@ -36,6 +36,8 @@
 #include <QSystemTrayIcon>
 #include <QStackedWidget>
 
+typedef int64_t putime_t;
+
 class QSettings;
 class QCloseEvent;
 class QKeyEvent;
@@ -261,7 +263,7 @@ private slots:
     void setBoss();
     void setRaise();
 
-    void showResumePanel( int64_t);
+    void showResumePanel( putime_t );
     void hideResumePanel();
     void resumePlayback();
 
