$NetBSD: patch-ui_qt_time__shift__dialog.cpp,v 1.1 2018/06/21 12:22:10 adam Exp $

Fix for Qt 5.11.

--- ui/qt/time_shift_dialog.cpp.orig	2018-06-21 09:15:54.000000000 +0000
+++ ui/qt/time_shift_dialog.cpp
@@ -14,6 +14,7 @@
 #include <ui/time_shift.h>
 #include <ui/qt/utils/tango_colors.h>
 
+#include <QStyleOption>
 
 TimeShiftDialog::TimeShiftDialog(QWidget *parent, capture_file *cf) :
     QDialog(parent),
