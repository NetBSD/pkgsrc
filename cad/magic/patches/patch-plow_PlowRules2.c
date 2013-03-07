$NetBSD: patch-plow_PlowRules2.c,v 1.2 2013/03/07 22:05:13 joerg Exp $

--- plow/PlowRules2.c.orig	2013-03-02 22:36:54.000000000 +0000
+++ plow/PlowRules2.c
@@ -235,9 +235,8 @@ prFixedPenumbraTop(edge)
     }
 }
 
-int
-prFixedPenumbraBot(edge)
-    Edge *edge;	/* Edge being moved */
+void
+prFixedPenumbraBot(Edge *edge)
 {
     struct applyRule ar;
     PlowRule *pr;
@@ -499,9 +498,8 @@ prCoverTop(edge)
     }
 }
 
-int
-prCoverBot(edge)
-    Edge *edge;	/* Edge being moved */
+void
+prCoverBot(Edge *edge)
 {
     TileType ltype, rtype;
     PlowRule *pr;
@@ -585,9 +583,8 @@ prIllegalTop(edge)
 		plowCoverTopProc, (ClientData) &ar);
 }
 
-int
-prIllegalBot(edge)
-    Edge *edge;
+void
+prIllegalBot(Edge *edge)
 {
     TileTypeBitMask insideTypes;
     struct applyRule ar;
