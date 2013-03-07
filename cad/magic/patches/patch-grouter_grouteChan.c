$NetBSD: patch-grouter_grouteChan.c,v 1.2 2013/03/07 22:05:12 joerg Exp $

--- grouter/grouteChan.c.orig	2013-03-02 22:19:28.000000000 +0000
+++ grouter/grouteChan.c
@@ -131,6 +131,11 @@ PaintArea *glChanPaintList;
  * ----------------------------------------------------------------------------
  */
 
+static void
+glChanShowTiles(char *mesg);
+static void
+glChanShowFunc(Tile *tile);
+
 void
 glChanBuildMap(chanList)
     GCRChannel *chanList;	/* List of all channels in routing problem */
@@ -435,11 +440,9 @@ glChanSetClient(tile, cdata)
     return 0;
 }
 
-int
-glChanShowTiles(mesg)
-    char *mesg;
+static void
+glChanShowTiles(char *mesg)
 {
-    int glChanShowFunc();
     char answer[100], m[1024];
 
     DBWAreaChanged(glChanDef, &TiPlaneRect, DBW_ALLWINDOWS, 0);
@@ -452,9 +455,8 @@ glChanShowTiles(mesg)
 	    &DBAllTypeBits, glChanShowFunc, (ClientData) NULL);
 }
 
-int
-glChanShowFunc(tile)
-    Tile *tile;
+static void
+glChanShowFunc(Tile *tile)
 {
     GCRChannel *ch;
     char mesg[1024];
