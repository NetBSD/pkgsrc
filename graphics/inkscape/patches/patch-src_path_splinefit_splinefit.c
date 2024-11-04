$NetBSD: patch-src_path_splinefit_splinefit.c,v 1.1 2024/11/04 10:10:57 jperkin Exp $

Avoid conflict with incompatible "extended" typedef on SunOS.

--- src/path/splinefit/splinefit.c.orig	2024-11-04 10:01:57.620685475 +0000
+++ src/path/splinefit/splinefit.c
@@ -408,7 +408,7 @@ static bigreal ClosestSplineSolve(Spline
     /* We want to find t so that spline(t) = sought */
     /*  find the value which is closest to close_to_t */
     /* on error return closetot */
-    extended ts[3];
+    xtended ts[3];
     int i;
     bigreal t, best, test;
 
@@ -436,7 +436,7 @@ static bigreal SigmaDeltas(Spline *splin
     int i;
     bigreal xdiff, ydiff, sum, temp, t;
     SplinePoint *to = spline->to, *from = spline->from;
-    extended ts[2], x,y;
+    xtended ts[2], x,y;
     struct dotbounds db2;
     bigreal dot;
     int near_vert, near_horiz;
@@ -888,11 +888,11 @@ return( SplineMake3(from,to));
 				*bunit.y-75*bunit.x*bunit.x*f*f*aunit.y);
 		quad.e = 80*bunit.y*(42*bunit.y*m-25*f*(bunit.y-bunit.x*f));
 	}
-	extended solutions[4] = {-999999,-999999,-999999,-999999};
+	xtended solutions[4] = {-999999,-999999,-999999,-999999};
 	_QuarticSolve(&quad,solutions);
-	extended abSolutions[10][2]; /* there are at most 4+4+1+1=10 solutions of pairs of a and b (quartic=0,derivative=0,b=0.01,a=0.01) */
+	xtended abSolutions[10][2]; /* there are at most 4+4+1+1=10 solutions of pairs of a and b (quartic=0,derivative=0,b=0.01,a=0.01) */
 	numberOfSolutions = 0;
-	extended a,b;
+	xtended a,b;
 	for( int i = 0; i < 4; i++ ){
 		a = solutions[i];
 		if ( a >= 0 && a < aMax ) {
