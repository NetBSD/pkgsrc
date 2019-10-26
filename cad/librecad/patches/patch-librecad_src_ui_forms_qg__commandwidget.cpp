$NetBSD: patch-librecad_src_ui_forms_qg__commandwidget.cpp,v 1.1 2019/10/26 12:23:01 kamil Exp $

Add missing include.

--- librecad/src/ui/forms/qg_commandwidget.cpp.orig	2018-02-15 20:54:45.000000000 +0000
+++ librecad/src/ui/forms/qg_commandwidget.cpp
@@ -27,6 +27,7 @@
 
 #include <algorithm>
 
+#include <QAction>
 #include <QKeyEvent>
 #include <QFileDialog>
 #include <QSettings>
