$NetBSD: patch-libgui_src_settings-dialog.h,v 1.1 2018/07/17 09:55:37 maya Exp $

Build fix.

--- libgui/src/settings-dialog.h.orig	2016-11-13 15:16:10.000000000 +0000
+++ libgui/src/settings-dialog.h
@@ -23,6 +23,7 @@ along with Octave; see the file COPYING.
 #if ! defined (octave_settings_dialog_h)
 #define octave_settings_dialog_h 1
 
+#include <QButtonGroup>
 #include <QDialog>
 #include <QSettings>
 #include <QLineEdit>
