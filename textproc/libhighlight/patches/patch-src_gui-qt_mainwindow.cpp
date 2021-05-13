$NetBSD: patch-src_gui-qt_mainwindow.cpp,v 1.4 2021/05/13 14:06:10 schmonz Exp $

Use X11 on Darwin, like everywhere else.

--- src/gui-qt/mainwindow.cpp.orig	2021-05-10 17:47:34.000000000 +0000
+++ src/gui-qt/mainwindow.cpp
@@ -36,6 +36,7 @@ along with Highlight.  If not, see <http
 #include "io_report.h"
 #include "syntax_chooser.h"
 
+#undef Q_OS_OSX
 
 #ifdef Q_OS_WIN
 #include <windows.h>
