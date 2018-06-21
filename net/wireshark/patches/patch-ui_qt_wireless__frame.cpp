$NetBSD: patch-ui_qt_wireless__frame.cpp,v 1.1 2018/06/21 12:22:10 adam Exp $

Fix for Qt 5.11.

--- ui/qt/wireless_frame.cpp.orig	2018-06-21 09:19:08.000000000 +0000
+++ ui/qt/wireless_frame.cpp
@@ -23,6 +23,7 @@
 #include <wsutil/frequency-utils.h>
 
 #include <QProcess>
+#include <QAbstractItemView>
 
 // To do:
 // - Disable or hide invalid channel types.
