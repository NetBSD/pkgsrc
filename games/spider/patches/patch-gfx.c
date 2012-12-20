$NetBSD: patch-gfx.c,v 1.1 2012/12/20 22:05:06 joerg Exp $

--- gfx.c.orig	1991-09-28 17:46:10.000000000 +0000
+++ gfx.c
@@ -115,6 +115,11 @@ static int	back_delta_x, back_delta_y; /
 static Bool	card_is_clipped;	/* optimizer for card drawing */
 #endif
 
+static void draw_did(Suit suit, int x, int y);
+static void draw_eight_pips(Suit suit, int x, int y);
+static void draw_six_pips(Suit suit, int x, int y);
+static void draw_center_pip(Suit suit, int x, int y);
+
 gfx_init(d, scr)
 Display	*d;
 int	scr;
@@ -566,8 +571,7 @@ force_redraw()
  *
  * REMIND -- spread the deck a bit to show that there's more
  */
-redraw_deck(x, y, w, h)
-int	x, y, w, h;
+void redraw_deck(int x, int y, int w, int h)
 {
 CardPtr	tmp;
 
@@ -599,8 +603,7 @@ CardPtr	tmp;
 }
 
 
-redraw_card_piles(x, y, w, h)
-int	x, y, w, h;
+void redraw_card_piles(int x, int y, int w, int h)
 {
 int	i;
 CardPtr	tmp;
@@ -641,8 +644,7 @@ CardPtr	tmp;
 }
 
 
-redraw_card_stacks(x, y, w, h)
-int	x, y, w, h;
+void redraw_card_stacks(int x, int y, int w, int h)
 {
 int	i;
 CardPtr	tmp;
@@ -1011,9 +1013,7 @@ int	w, h;
  *
  * location is for center of pip
  */
-draw_did(suit, x, y)
-Suit	suit;
-int	x,y;
+static void draw_did(Suit suit, int x, int y)
 {
 int	w, h;
 
@@ -1051,9 +1051,7 @@ int	w, h;
 /*
  * draws big center pip
  */
-draw_center_pip(suit, x, y)
-Suit	suit;
-int	x,y;
+static void draw_center_pip(Suit suit, int x, int y)
 {
 int	w, h;
 
@@ -1110,9 +1108,7 @@ int	x,y;
 	draw_did(suit, x + CARD_COL3_X, y + CARD_ROW5_Y);
 }
 
-draw_six_pips(suit, x, y)
-Suit	suit;
-int	x, y;
+static void draw_six_pips(Suit suit, int x, int y)
 {
 	draw_pip(suit, x + CARD_COL1_X, y + CARD_ROW1_Y);
 
@@ -1129,9 +1125,7 @@ int	x, y;
 	draw_did(suit, x + CARD_COL3_X, y + CARD_ROW5_Y);
 }
 
-draw_eight_pips(suit, x, y)
-Suit	suit;
-int	x,y;
+static void draw_eight_pips(Suit suit, int x, int y)
 {
 	draw_pip(suit, x + CARD_COL1_X, y + CARD_ROW1_Y);
 
