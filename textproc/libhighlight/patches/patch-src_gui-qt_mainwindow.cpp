$NetBSD: patch-src_gui-qt_mainwindow.cpp,v 1.1 2018/07/27 07:39:12 schmonz Exp $

Use X11 on Darwin, like everywhere else.

--- src/gui-qt/mainwindow.cpp.orig	2018-07-19 17:57:22.000000000 +0000
+++ src/gui-qt/mainwindow.cpp
@@ -36,6 +36,8 @@ along with Highlight.  If not, see <http
 #include "io_report.h"
 #include "syntax_chooser.h"
 
+#undef Q_OS_OSX
+
 MainWindow::MainWindow(QWidget *parent)
     : QMainWindow(parent), ui(new Ui::MainWindowClass), themesClassicIdx(0), themesBase16Idx(0), getDataFromCP(false)
 {
