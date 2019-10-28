$NetBSD: patch-src_qt_ui_UICheatRaw.cpp,v 1.1 2019/10/28 09:33:29 kamil Exp $

Fix Qt 5.11.

--- src/qt/ui/UICheatRaw.cpp.orig	2016-08-19 15:31:13.000000000 +0000
+++ src/qt/ui/UICheatRaw.cpp
@@ -20,8 +20,6 @@
 #include "UIHexInput.h"
 #include "../QtYabause.h"
 
-#include <QButtonGroup>
-
 UICheatRaw::UICheatRaw( QWidget* p )
 	: QDialog( p )
 {
