$NetBSD: patch-include_libg.h,v 1.1 2017/09/21 14:37:40 bsiegert Exp $

--- include/libg.h.orig	2017-09-21 13:54:43.000000000 +0000
+++ include/libg.h
@@ -94,12 +94,12 @@ struct	Fontchar
 
 struct	Subfont
 {
-	short		minrow;	/* first character row in font (for X subfonts) */
-	short		mincol;	/* first character col in font (for X subfonts) */
-	short		minchar; /* first char code in subfont */
-	short		maxchar; /* last char code in subfont */
-	short		width;	/* number of chars in row */
-	short		n;	/* number of chars in font */
+	int		minrow;	/* first character row in font (for X subfonts) */
+	int		mincol;	/* first character col in font (for X subfonts) */
+	int		minchar; /* first char code in subfont */
+	int		maxchar; /* last char code in subfont */
+	int		width;	/* number of chars in row */
+	int		n;	/* number of chars in font */
 	unsigned char	height;	/* height of bitmap */
 	char		ascent;	/* top of bitmap to baseline */
 	Fontchar	*info;	/* n+1 character descriptors */
