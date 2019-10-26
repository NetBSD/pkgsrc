$NetBSD: patch-librecad_src_ui_generic_colorwizard.cpp,v 1.1 2019/10/26 12:23:01 kamil Exp $

Add missing include.

--- librecad/src/ui/generic/colorwizard.cpp.orig	2018-02-15 20:54:45.000000000 +0000
+++ librecad/src/ui/generic/colorwizard.cpp
@@ -27,6 +27,7 @@
 #include "colorwizard.h"
 #include "ui_colorwizard.h"
 
+#include <QAction>
 #include <QColorDialog>
 #include <QLineEdit>
 #include <QListWidget>
