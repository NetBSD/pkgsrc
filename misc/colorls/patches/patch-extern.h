$NetBSD: patch-extern.h,v 1.2 2015/07/09 11:44:09 jperkin Exp $

Add colors.

--- extern.h.orig	1994-09-24 02:55:52.000000000 +0000
+++ extern.h
@@ -49,3 +49,6 @@ void	 printcol __P((DISPLAY *));
 void	 printlong __P((DISPLAY *));
 void	 printscol __P((DISPLAY *));
 void	 usage __P((void));
+
+void	 parsecolors(char *);
+int	 colortype(mode_t);
