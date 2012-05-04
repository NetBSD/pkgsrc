$NetBSD: patch-kpat_dealer.h,v 1.1 2012/05/04 16:15:33 joerg Exp $

--- kpat/dealer.h.orig	2012-04-27 19:43:39.000000000 +0000
+++ kpat/dealer.h
@@ -38,16 +38,7 @@ public:
     virtual Dealer *createGame(KMainWindow *parent) = 0;
 };
 
-class CardState;
-
-typedef QValueList<CardState> CardStateList;
-
-struct State
-{
-    CardStateList cards;
-    QString gameData;
-};
-
+struct State;
 
 /***************************************************************
 
@@ -114,7 +105,7 @@ public:
     void setAutoDropEnabled(bool a);
     bool autoDrop() const { return _autodrop; }
 
-    int getMoves() const { return undoList.count(); }
+    int getMoves();
 
 public slots:
 
