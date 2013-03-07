$NetBSD: patch-plow_PlowMain.c,v 1.2 2013/03/07 22:05:13 joerg Exp $

--- plow/PlowMain.c.orig	2013-03-02 22:35:26.000000000 +0000
+++ plow/PlowMain.c
@@ -84,11 +84,15 @@ RuleTableEntry *plowCellRulesPtr = plowC
 extern int prClearUmbra();
 extern int prUmbra();
 extern int prPenumbraTop(), prPenumbraBot();
-extern int prFixedPenumbraTop(), prFixedPenumbraBot();
-extern int prSliverTop(), prSliverBot();
+extern int prFixedPenumbraTop();
+void prFixedPenumbraBot(Edge *edge);
+void prSliverBot(Edge *edge, PlowRule *rules);
+void prIllegalBot(Edge *edge);
+void prCoverBot(Edge *edge);
+extern int prSliverTop();
 extern int prInSliver();
-extern int prIllegalTop(), prIllegalBot();
-extern int prCoverTop(), prCoverBot();
+extern int prIllegalTop();
+extern int prCoverTop();
 extern int prFixedLHS(), prFixedRHS(), prFixedDragStubs();
 extern int prContactLHS(), prContactRHS();
 extern int prFindCells();
@@ -1171,9 +1175,8 @@ plowFindSelCell(yankUse, editUse)
  * ----------------------------------------------------------------------------
  */
 
-int
-PlowExtendJogHorizon(edge)
-    Edge *edge;			/* Edge being moved */
+static void
+PlowExtendJogHorizon(Edge *edge)
 {
     int horizonTop, horizonBot, eTop, eBot;
     Tile *tpR, *tpL;
