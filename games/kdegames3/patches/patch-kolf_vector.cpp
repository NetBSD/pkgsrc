$NetBSD: patch-kolf_vector.cpp,v 1.1 2013/09/12 20:11:30 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous"

--- kolf/vector.cpp.orig	2005-09-10 08:18:11.000000000 +0000
+++ kolf/vector.cpp
@@ -6,14 +6,14 @@
 
 // Creates a vector with between two points
 Vector::Vector(const QPoint &source, const QPoint &dest) {
-	_magnitude = sqrt(pow(source.x() - dest.x(), 2) + pow(source.y() - dest.y(), 2));
-	_direction = atan2(source.y() - dest.y(), source.x() - dest.x());
+	_magnitude = sqrt(pow((float)source.x() - dest.x(), 2) + pow((float)source.y() - dest.y(), 2));
+	_direction = atan2((float)source.y() - dest.y(), source.x() - dest.x());
 }
 
 // Creates a vector with between two points
 Vector::Vector(const Point &source, const Point &dest) {
-	_magnitude = sqrt(pow(source.x - dest.x, 2) + pow(source.y - dest.y, 2));
-	_direction = atan2(source.y - dest.y, source.x - dest.x);
+	_magnitude = sqrt(pow((float)source.x - dest.x, 2) + pow((float)source.y - dest.y, 2));
+	_direction = atan2((float)source.y - dest.y, source.x - dest.x);
 }
 
 // Creates an empty Vector
