$NetBSD: patch-VisualEditor_Actions_SelectMoveHandAction.cpp,v 1.1 2016/12/15 23:58:18 joerg Exp $

QFlags are for ORing together, not ANDing.

--- VisualEditor/Actions/SelectMoveHandAction.cpp.orig	2016-12-15 15:40:54.181414380 +0000
+++ VisualEditor/Actions/SelectMoveHandAction.cpp
@@ -84,7 +84,7 @@ bool SelectMoveHandAction::executePress(
 
     if (_graphScene->items().count() > 600) { // 5! + 25 items on screen
         _graphScene->views().at(0)->setRenderHints(QPainter::Antialiasing
-                & QPainter::TextAntialiasing);
+                | QPainter::TextAntialiasing);
     }
     return true;
 }
