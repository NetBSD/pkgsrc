$NetBSD: patch-src_qt_ui_UIHexInput.h,v 1.1 2019/10/28 09:33:29 kamil Exp $

Fix Qt 5.11.

--- src/qt/ui/UIHexInput.h.orig	2016-08-19 15:31:13.000000000 +0000
+++ src/qt/ui/UIHexInput.h
@@ -22,6 +22,8 @@
 #include "ui_UIHexInput.h"
 #include "../QtYabause.h"
 
+#include <QValidator>
+
 class HexValidator : public QValidator
 {
    Q_OBJECT
