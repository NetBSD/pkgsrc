$NetBSD: patch-src_gui-qt_mainwindow.cpp,v 1.3 2019/05/21 21:56:57 schmonz Exp $

Use X11 on Darwin, like everywhere else.

--- src/gui-qt/mainwindow.cpp.orig	2019-05-17 19:04:13.000000000 +0000
+++ src/gui-qt/mainwindow.cpp
@@ -36,6 +36,8 @@ along with Highlight.  If not, see <http
 #include "io_report.h"
 #include "syntax_chooser.h"
 
+#undef Q_OS_OSX
+
 #ifdef Q_OS_WIN
 #include <windows.h>
 #endif
