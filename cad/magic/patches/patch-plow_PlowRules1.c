$NetBSD: patch-plow_PlowRules1.c,v 1.2 2013/03/07 22:05:13 joerg Exp $

--- plow/PlowRules1.c.orig	2013-03-02 22:36:15.000000000 +0000
+++ plow/PlowRules1.c
@@ -529,10 +529,8 @@ prSliverTop(edge, rules)
     }
 }
 
-int
-prSliverBot(edge, rules)
-    Edge *edge;
-    PlowRule *rules;
+void
+prSliverBot(Edge *edge, PlowRule *rules)
 {
     TileTypeBitMask insideTypes;
     PlowRule *pr;
