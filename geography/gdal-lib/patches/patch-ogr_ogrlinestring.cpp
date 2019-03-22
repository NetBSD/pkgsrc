$NetBSD: patch-ogr_ogrlinestring.cpp,v 1.1 2019/03/22 14:00:49 gdt Exp $

fabs is not in std.   Sent upstream via mail

--- ogr/ogrlinestring.cpp.orig	2019-03-15 12:35:19.000000000 +0000
+++ ogr/ogrlinestring.cpp
@@ -2551,7 +2551,7 @@ void OGRSimpleCurve::segmentize( double 
         const double dfX = paoPoints[i+1].x - paoPoints[i].x;
         const double dfY = paoPoints[i+1].y - paoPoints[i].y;
         const double dfSquareDist = dfX * dfX + dfY * dfY;
-        if( std::fabs(dfSquareDist - dfSquareMaxLength) > 1e-5 * dfSquareMaxLength )
+        if( fabs(dfSquareDist - dfSquareMaxLength) > 1e-5 * dfSquareMaxLength )
         {
             const double dfIntermediatePoints =
                 floor(sqrt(dfSquareDist / dfSquareMaxLength) - 1e-2);
