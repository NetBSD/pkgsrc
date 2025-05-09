$NetBSD: patch-out.c,v 1.1 2025/05/09 06:27:32 wiz Exp $

1.83 from upstream, without the RCS Id change:

Revert part of the previous diff to fix a regression (another endless loop)
reported by Michael <Stapelberg at Debian> in the Linux md(4) manual.

The reason the colwidth[] array is needed is not that it stores widths
different from those in tbl->cols[].width, but that only part of the
columns participate in the comparisons, i.e. only those intersecting 
at least one span the still requires width distribution.

--- out.c.orig	2021-09-23 18:03:23.000000000 +0000
+++ out.c
@@ -123,6 +123,7 @@ tblcalc(struct rofftbl *tbl, const struc
 	const struct tbl_dat	*dp;
 	struct roffcol		*col;
 	struct tbl_colgroup	*first_group, **gp, *g;
+	size_t			*colwidth;
 	size_t			 ewidth, min1, min2, wanted, width, xwidth;
 	int			 done, icol, maxcol, necol, nxcol, quirkcol;
 
@@ -256,16 +257,28 @@ tblcalc(struct rofftbl *tbl, const struc
 			gp = &(*gp)->next;
 	}
 
+	colwidth = mandoc_reallocarray(NULL, maxcol + 1, sizeof(*colwidth));
 	while (first_group != NULL) {
 
 		/*
+		 * Rebuild the array of the widths of all columns
+		 * participating in spans that require expansion.
+		 */
+
+		for (icol = 0; icol <= maxcol; icol++)
+			colwidth[icol] = SIZE_MAX;
+		for (g = first_group; g != NULL; g = g->next)
+			for (icol = g->startcol; icol <= g->endcol; icol++)
+				colwidth[icol] = tbl->cols[icol].width;
+
+		/*
 		 * Find the smallest and second smallest column width
 		 * among the columns which may need expamsion.
 		 */
 
 		min1 = min2 = SIZE_MAX;
 		for (icol = 0; icol <= maxcol; icol++) {
-			width = tbl->cols[icol].width;
+			width = colwidth[icol];
 			if (min1 > width) {
 				min2 = min1;
 				min1 = width;
@@ -283,7 +296,7 @@ tblcalc(struct rofftbl *tbl, const struc
 		for (g = first_group; g != NULL; g = g->next) {
 			necol = 0;
 			for (icol = g->startcol; icol <= g->endcol; icol++)
-				if (tbl->cols[icol].width == min1)
+				if (colwidth[icol] == min1)
 					necol++;
 			if (necol == 0)
 				continue;
@@ -300,7 +313,7 @@ tblcalc(struct rofftbl *tbl, const struc
 		while ((g = *gp) != NULL) {
 			done = 0;
 			for (icol = g->startcol; icol <= g->endcol; icol++) {
-				if (tbl->cols[icol].width != min1)
+				if (colwidth[icol] != min1)
 					continue;
 				if (g->wanted <= wanted - min1) {
 					tbl->cols[icol].width += g->wanted;
@@ -317,6 +330,7 @@ tblcalc(struct rofftbl *tbl, const struc
 				gp = &(*gp)->next;
 		}
 	}
+	free(colwidth);
 
 	/*
 	 * Align numbers with text.
