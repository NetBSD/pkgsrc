$NetBSD: patch-src_path_splinefit_splinefont.h,v 1.1 2024/11/04 10:10:57 jperkin Exp $

Avoid conflict with incompatible "extended" typedef on SunOS.

--- src/path/splinefit/splinefont.h.orig	2024-11-04 09:53:31.013145555 +0000
+++ src/path/splinefit/splinefont.h
@@ -7,7 +7,7 @@
 
 typedef double real;
 typedef double bigreal;
-typedef double extended;
+typedef double xtended;
 typedef int BOOL;
 
 #define chunkalloc(size)	calloc(1,size)
@@ -123,7 +123,7 @@ SplinePoint *SplinePointCreate(real x, r
 void SplineRefigure3(Spline *spline);
 void SplineRefigure(Spline *spline);
 int SplineIsLinear(Spline *spline);
-void SplineFindExtrema(const Spline1D *sp, extended *_t1, extended *_t2 );
+void SplineFindExtrema(const Spline1D *sp, xtended *_t1, xtended *_t2 );
 bigreal SplineMinDistanceToPoint(Spline *s, BasePoint *p);
 
 void SplinePointFree(SplinePoint *sp);
@@ -134,8 +134,8 @@ bigreal BPDot(BasePoint v1, BasePoint v2
 bigreal BPCross(BasePoint v1, BasePoint v2);
 BasePoint BPRev(BasePoint v);
 
-int _CubicSolve(const Spline1D *sp,bigreal sought, extended ts[3]);
-int _QuarticSolve(Quartic *q,extended ts[4]);
+int _CubicSolve(const Spline1D *sp,bigreal sought, xtended ts[3]);
+int _QuarticSolve(Quartic *q,xtended ts[4]);
 int IntersectLines(BasePoint *inter,
 	BasePoint *line1_1, BasePoint *line1_2,
 	BasePoint *line2_1, BasePoint *line2_2);
