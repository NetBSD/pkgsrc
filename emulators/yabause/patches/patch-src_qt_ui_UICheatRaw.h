$NetBSD: patch-src_qt_ui_UICheatRaw.h,v 1.1 2019/10/28 09:33:29 kamil Exp $

Fix Qt 5.11.

--- src/qt/ui/UICheatRaw.h.orig	2016-08-19 15:31:13.000000000 +0000
+++ src/qt/ui/UICheatRaw.h
@@ -21,7 +21,7 @@
 
 #include "ui_UICheatRaw.h"
 
-class QButtonGroup;
+#include <QButtonGroup>
 
 class UICheatRaw : public QDialog, public Ui::UICheatRaw
 {
