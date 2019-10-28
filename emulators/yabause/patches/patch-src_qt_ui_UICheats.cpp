$NetBSD: patch-src_qt_ui_UICheats.cpp,v 1.1 2019/10/28 09:33:29 kamil Exp $

Fix Qt 5.11.

--- src/qt/ui/UICheats.cpp.orig	2016-08-19 15:31:13.000000000 +0000
+++ src/qt/ui/UICheats.cpp
@@ -21,6 +21,8 @@
 #include "UICheatRaw.h"
 #include "../CommonDialogs.h"
 
+#include <QButtonGroup>
+
 UICheats::UICheats( QWidget* p )
 	: QDialog( p )
 {
