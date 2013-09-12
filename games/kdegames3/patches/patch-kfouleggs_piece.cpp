$NetBSD: patch-kfouleggs_piece.cpp,v 1.1 2013/09/12 20:11:30 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous"

--- kfouleggs/piece.cpp.orig	2005-09-10 08:18:28.000000000 +0000
+++ kfouleggs/piece.cpp
@@ -49,13 +49,13 @@ void FEPieceInfo::setMask(QPixmap *pixma
 
 	// base circle
     int w = pixmap->width();
-	int d = (int)((sqrt(2)-2./3)*w);
+	int d = (int)((sqrt(2.)-2./3)*w);
 	QRect cr = QRect(0, 0, d, d);
 	cr.moveCenter(QPoint(w/2, w/2));
 	p.drawEllipse(cr);
 
 	if (blockMode) {
-        int a  = (int)(w/(3.*sqrt(2)));
+        int a  = (int)(w/(3.*sqrt(2.)));
         int ra = 2*w/3+1;
         cr = QRect(0, 0, ra, ra);
 
