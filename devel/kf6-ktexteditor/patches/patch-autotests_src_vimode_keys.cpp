$NetBSD: patch-autotests_src_vimode_keys.cpp,v 1.1 2025/11/27 22:32:25 wiz Exp $

Fix build with qt6 6.10.
https://github.com/KDE/ktexteditor/commit/33936c0fd561fa0e84a44b325a4501f8847cd68d

--- autotests/src/vimode/keys.cpp.orig	2025-09-08 08:14:38.000000000 +0000
+++ autotests/src/vimode/keys.cpp
@@ -722,7 +722,7 @@ void KeysTest::AltGr()
     QApplication::postEvent(kate_view->focusProxy(), altGrDown);
     QApplication::sendPostedEvents();
     QKeyEvent *altGrAndUGrave = new QKeyEvent(QEvent::KeyPress, Qt::Key_Ugrave, Qt::ShiftModifier | Qt::GroupSwitchModifier, ugrave);
-    qDebug() << QStringLiteral("%1").arg(altGrAndUGrave->modifiers(), 10, 16);
+    qDebug() << QStringLiteral("%1").arg(static_cast<int>(altGrAndUGrave->modifiers()), 10, 16);
     QApplication::postEvent(kate_view->focusProxy(), altGrAndUGrave);
     QApplication::sendPostedEvents();
     altGrUp = new QKeyEvent(QEvent::KeyRelease, Qt::Key_AltGr, Qt::NoModifier);
