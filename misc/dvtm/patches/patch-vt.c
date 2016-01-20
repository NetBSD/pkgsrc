$NetBSD: patch-vt.c,v 1.1 2016/01/20 14:34:35 leot Exp $

Avoid a possible bug when colors are encountered (also imported upstream).

--- vt.c.orig	2016-01-09 11:40:56.000000000 +0000
+++ vt.c
@@ -1827,6 +1827,14 @@ static void init_colors(void)
 	color_pairs_max = MIN(COLOR_PAIRS, MAX_COLOR_PAIRS);
 	if (COLORS)
 		color2palette = calloc((COLORS + 2) * (COLORS + 2), sizeof(short));
+	/*
+	 * XXX: On undefined color-pairs NetBSD curses pair_content() set fg
+	 *      and bg to default colors while ncurses set them respectively to
+	 *      0 and 0. Initialize all color-pairs in order to have consistent
+	 *      behaviour despite the implementation used.
+	 */
+	for (short i = 1; i < COLOR_PAIRS; i++)
+		init_pair(i, 0, 0);
 	vt_color_reserve(COLOR_WHITE, COLOR_BLACK);
 }
 
