$NetBSD: patch-src_CompletingEdit.cpp,v 1.1 2020/03/01 12:38:04 markd Exp $

From ArchLinux
This is a temporary workaround for a regression in Qt 5.14.0, see
https://github.com/TeXworks/texworks/issues/883 and
https://bugreports.qt.io/browse/QTBUG-80831.

--- src/CompletingEdit.cpp.orig	2019-03-16 17:06:14.000000000 +0000
+++ src/CompletingEdit.cpp
@@ -87,6 +87,9 @@ CompletingEdit::CompletingEdit(QWidget *
 	cursorPositionChangedSlot();
 	updateLineNumberAreaWidth(0);
 	updateColors();
+
+	// Workaround for Qt 5.14, see https://bugreports.qt.io/browse/QTBUG-80831
+	setMouseTracking(false);
 }
 
 void CompletingEdit::prefixLines(const QString &prefix)
