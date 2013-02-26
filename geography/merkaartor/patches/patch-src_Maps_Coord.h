$NetBSD: patch-src_Maps_Coord.h,v 1.1 2013/02/26 11:15:19 joerg Exp $

--- src/Maps/Coord.h.orig	2013-02-25 22:20:17.000000000 +0000
+++ src/Maps/Coord.h
@@ -127,7 +127,7 @@ class Coord
 uint qHash(const Coord &c);
 
 
-#ifndef _MOBILE
+#if !defined(_MOBILE) && !defined(Q_MOC_RUN)
 #include <ggl/ggl.hpp>
 #include <ggl/geometries/register/point.hpp>
 
@@ -312,7 +312,7 @@ class CoordBox
 
 Q_DECLARE_METATYPE( CoordBox );
 
-#ifndef _MOBILE
+#if !defined(_MOBILE) && !defined(Q_MOC_RUN)
 #include <ggl/geometries/register/box.hpp>
 
 GEOMETRY_REGISTER_BOX(CoordBox, Coord, BottomLeft, TopRight)
