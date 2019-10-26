$NetBSD: patch-librecad_src_ui_generic_widgetcreator.cpp,v 1.1 2019/10/26 12:23:01 kamil Exp $

Add missing includes.

--- librecad/src/ui/generic/widgetcreator.cpp.orig	2018-02-15 20:54:45.000000000 +0000
+++ librecad/src/ui/generic/widgetcreator.cpp
@@ -27,6 +27,8 @@
 #include "widgetcreator.h"
 #include "ui_widgetcreator.h"
 
+#include <QAction>
+#include <QActionGroup>
 #include <QSettings>
 #include <QLineEdit>
 #include <QPushButton>
