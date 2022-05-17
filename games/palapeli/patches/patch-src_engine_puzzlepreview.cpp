$NetBSD: patch-src_engine_puzzlepreview.cpp,v 1.3 2022/05/17 17:41:30 jperkin Exp $

Avoid ambiguous function call.

--- src/engine/puzzlepreview.cpp.orig	2021-02-24 23:27:44.000000000 +0000
+++ src/engine/puzzlepreview.cpp
@@ -26,6 +26,8 @@
 #include <QPainter>
 #include <KLocalizedString>
 
+using std::sqrt;
+
 Palapeli::PuzzlePreview::PuzzlePreview(QWidget* parent)
 {
 	m_settingsSaveTimer = new QTimer(this);
