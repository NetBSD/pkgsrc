$NetBSD: patch-src_gui-qt_mainwindow.cpp,v 1.2 2019/02/12 19:46:12 schmonz Exp $

Use X11 on Darwin, like everywhere else.

--- src/gui-qt/mainwindow.cpp.orig	2019-02-06 20:21:57.000000000 +0000
+++ src/gui-qt/mainwindow.cpp
@@ -36,6 +36,8 @@ along with Highlight.  If not, see <http
 #include "io_report.h"
 #include "syntax_chooser.h"
 
+#undef Q_OS_OSX
+
 //#include <QDebug>
 
 MainWindow::MainWindow(QWidget *parent)
