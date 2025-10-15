$NetBSD: patch-src_Gui_Window.cpp,v 1.1 2025/10/15 16:20:05 hauke Exp $

Add missing include.

--- src/Gui/Window.cpp.orig	2025-10-15 14:59:15.541845017 +0000
+++ src/Gui/Window.cpp
@@ -32,6 +32,7 @@
 #include <QKeyEvent>
 #include <QMenuBar>
 #include <QMessageBox>
+#include <QPainterPath>
 #include <QProgressBar>
 #include <QScrollBar>
 #include <QSplitter>
