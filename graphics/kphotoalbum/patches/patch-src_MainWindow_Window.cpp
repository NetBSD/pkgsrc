$NetBSD: patch-src_MainWindow_Window.cpp,v 1.1 2011/11/24 14:00:53 joerg Exp $

--- src/MainWindow/Window.cpp.orig	2011-11-24 02:01:28.000000000 +0000
+++ src/MainWindow/Window.cpp
@@ -108,6 +108,7 @@
 #include <kurldrag.h>
 #include <qclipboard.h>
 #include <stdexcept>
+#include <typeinfo>
 
 MainWindow::Window* MainWindow::Window::_instance = 0;
 
