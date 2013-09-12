$NetBSD: patch-kolf_slope.cpp,v 1.1 2013/09/12 20:11:30 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous"

--- kolf/slope.cpp.orig	2005-09-10 08:18:11.000000000 +0000
+++ kolf/slope.cpp
@@ -396,7 +396,7 @@ void Slope::updatePixmap()
 	p.drawTiledPixmap(QRect(0, 0, width(), height()), grass);
 	p.end();
 
-	const double length = sqrt(width() * width() + height() * height()) / 4;
+	const double length = sqrt((float)width() * width() + height() * height()) / 4;
 
 	if (circle)
 	{
