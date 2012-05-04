$NetBSD: patch-kpat_dealer.cpp,v 1.1 2012/05/04 16:15:33 joerg Exp $

--- kpat/dealer.cpp.orig	2012-04-27 19:43:49.000000000 +0000
+++ kpat/dealer.cpp
@@ -715,12 +715,26 @@ public:
     }
 };
 
+typedef QValueList<CardState> CardStateList;
+
+struct State
+{
+    CardStateList cards;
+    QString gameData;
+};
+
 typedef class QValueList<CardState> CardStateList;
 
 bool operator==( const State & st1, const State & st2) {
     return st1.cards == st2.cards && st1.gameData == st2.gameData;
 }
 
+int
+Dealer::getMoves()
+{
+    return undoList.count();
+}
+
 State *Dealer::getState()
 {
     QCanvasItemList list = canvas()->allItems();
