$NetBSD: patch-kolf_floater.cpp,v 1.1 2013/09/12 20:11:30 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous"

--- kolf/floater.cpp.orig	2005-09-10 08:18:11.000000000 +0000
+++ kolf/floater.cpp
@@ -31,7 +31,7 @@ void FloaterGuide::moveBy(double dx, dou
 
 void FloaterGuide::setPoints(int xa, int ya, int xb, int yb)
 {
-	if (fabs(xa - xb) > 0 || fabs(ya - yb) > 0)
+	if (fabs((float)xa - xb) > 0 || fabs((float)ya - yb) > 0)
 	{
 		Wall::setPoints(xa, ya, xb, yb);
 		if (floater)
