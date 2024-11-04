$NetBSD: patch-src_path_splinefit_splinefont.c,v 1.1 2024/11/04 10:10:57 jperkin Exp $

Avoid conflict with incompatible "extended" typedef on SunOS.

--- src/path/splinefit/splinefont.c.orig	2024-11-04 10:00:10.828146677 +0000
+++ src/path/splinefit/splinefont.c
@@ -339,9 +339,9 @@ return( t );
 return( t );
 }
 
-void SplineFindExtrema(const Spline1D *sp, extended *_t1, extended *_t2 ) {
-    extended t1= -1, t2= -1;
-    extended b2_fourac;
+void SplineFindExtrema(const Spline1D *sp, xtended *_t1, xtended *_t2 ) {
+    xtended t1= -1, t2= -1;
+    xtended b2_fourac;
 
     /* Find the extreme points on the curve */
     /*  Set to -1 if there are none or if they are outside the range [0,1] */
@@ -351,14 +351,14 @@ void SplineFindExtrema(const Spline1D *s
     /*  (Does not check to see if d/dt==0 points are inflection points (rather than extrema) */
     if ( sp->a!=0 ) {
 	/* cubic, possibly 2 extrema (possibly none) */
-	b2_fourac = 4*(extended) sp->b*sp->b - 12*(extended) sp->a*sp->c;
+	b2_fourac = 4*(xtended) sp->b*sp->b - 12*(xtended) sp->a*sp->c;
 	if ( b2_fourac>=0 ) {
 	    b2_fourac = sqrt(b2_fourac);
 	    t1 = (-2*sp->b - b2_fourac) / (6*sp->a);
 	    t2 = (-2*sp->b + b2_fourac) / (6*sp->a);
 	    t1 = CheckExtremaForSingleBitErrors(sp,t1,t2);
 	    t2 = CheckExtremaForSingleBitErrors(sp,t2,t1);
-	    if ( t1>t2 ) { extended temp = t1; t1 = t2; t2 = temp; }
+	    if ( t1>t2 ) { xtended temp = t1; t1 = t2; t2 = temp; }
 	    else if ( t1==t2 ) t2 = -1;
 	    if ( RealNear(t1,0)) t1=0; else if ( RealNear(t1,1)) t1=1;
 	    if ( RealNear(t2,0)) t2=0; else if ( RealNear(t2,1)) t2=1;
@@ -367,7 +367,7 @@ void SplineFindExtrema(const Spline1D *s
 	}
     } else if ( sp->b!=0 ) {
 	/* Quadratic, at most one extremum */
-	t1 = -sp->c/(2.0*(extended) sp->b);
+	t1 = -sp->c/(2.0*(xtended) sp->b);
 	if ( t1<=0 || t1>=1 ) t1 = -1;
     } else /*if ( sp->c!=0 )*/ {
 	/* linear, no extrema */
@@ -421,10 +421,10 @@ int IntersectLines(BasePoint *inter,
 }
 
 static int MinMaxWithin(Spline *spline) {
-    extended dx, dy;
+    xtended dx, dy;
     int which;
-    extended t1, t2;
-    extended w;
+    xtended t1, t2;
+    xtended w;
     /* We know that this "spline" is basically one dimensional. As long as its*/
     /*  extrema are between the start and end points on that line then we can */
     /*  treat it as a line. If the extrema are way outside the line segment */
@@ -719,9 +719,9 @@ return( -1 );
 /* I use -999999 as an error flag, since we're really only interested in */
 /*  solns near 0 and 1 that should be ok. -1 is perhaps a little too close */
 /* Sigh. When solutions are near 0, the rounding errors are appalling. */
-int _CubicSolve(const Spline1D *sp,bigreal sought, extended ts[3]) {
-    extended d, xN, yN, delta2, temp, delta, h, t2, t3, theta;
-    extended sa=sp->a, sb=sp->b, sc=sp->c, sd=sp->d-sought;
+int _CubicSolve(const Spline1D *sp,bigreal sought, xtended ts[3]) {
+    xtended d, xN, yN, delta2, temp, delta, h, t2, t3, theta;
+    xtended sa=sp->a, sb=sp->b, sc=sp->c, sd=sp->d-sought;
     int i=0;
 
     ts[0] = ts[1] = ts[2] = -999999;
@@ -729,24 +729,24 @@ int _CubicSolve(const Spline1D *sp,bigre
 	/* one of the roots is 0, the other two are the soln of a quadratic */
 	ts[0] = 0;
 	if ( sc==0 ) {
-	    ts[1] = -sb/(extended) sa;	/* two zero roots */
+	    ts[1] = -sb/(xtended) sa;	/* two zero roots */
 	} else {
-	    temp = sb*(extended) sb-4*(extended) sa*sc;
+	    temp = sb*(xtended) sb-4*(xtended) sa*sc;
 	    if ( RealNear(temp,0))
-		ts[1] = -sb/(2*(extended) sa);
+		ts[1] = -sb/(2*(xtended) sa);
 	    else if ( temp>=0 ) {
 		temp = sqrt(temp);
-		ts[1] = (-sb+temp)/(2*(extended) sa);
-		ts[2] = (-sb-temp)/(2*(extended) sa);
+		ts[1] = (-sb+temp)/(2*(xtended) sa);
+		ts[2] = (-sb-temp)/(2*(xtended) sa);
 	    }
 	}
     } else if ( sa!=0 ) {
     /* http://www.m-a.org.uk/eb/mg/mg077ch.pdf */
     /* this nifty solution to the cubic neatly avoids complex arithmetic */
-	xN = -sb/(3*(extended) sa);
+	xN = -sb/(3*(xtended) sa);
 	yN = ((sa*xN + sb)*xN+sc)*xN + sd;
 
-	delta2 = (sb*(extended) sb-3*(extended) sa*sc)/(9*(extended) sa*sa);
+	delta2 = (sb*(xtended) sb-3*(xtended) sa*sc)/(9*(xtended) sa*sa);
 	/*if ( RealWithin(delta2,0,.00000001) ) delta2 = 0;*/
 
 	/* the descriminant is yN^2-h^2, but delta might be <0 so avoid using h */
@@ -782,23 +782,23 @@ int _CubicSolve(const Spline1D *sp,bigre
 	    if ( xN>=-0.0001 && xN<=1.0001 ) ts[0] = xN;
 	}
     } else if ( sb!=0 ) {
-	extended d = sc*(extended) sc-4*(extended) sb*sd;
+	xtended d = sc*(xtended) sc-4*(xtended) sb*sd;
 	if ( d<0 && RealNear(d,0)) d=0;
 	if ( d<0 )
 return(false);		/* All roots imaginary */
 	d = sqrt(d);
-	ts[0] = (-sc-d)/(2*(extended) sb);
-	ts[1] = (-sc+d)/(2*(extended) sb);
+	ts[0] = (-sc-d)/(2*(xtended) sb);
+	ts[1] = (-sc+d)/(2*(xtended) sb);
     } else if ( sc!=0 ) {
-	ts[0] = -sd/(extended) sc;
+	ts[0] = -sd/(xtended) sc;
     } else {
 	/* If it's a point then either everything is a solution, or nothing */
     }
 return( ts[0]!=-999999 );
 }
 
-int _QuarticSolve(Quartic *q,extended ts[4]) {
-    extended extrema[5];
+int _QuarticSolve(Quartic *q,xtended ts[4]) {
+    xtended extrema[5];
     Spline1D sp;
     int ecnt = 0, i, zcnt;
 
@@ -828,15 +828,15 @@ return( _CubicSolve(&sp,0,ts+1)+1);
 	if ( extrema[1]!=-999999 ) {
 	    ecnt = 2;
 	    if ( extrema[1]<extrema[0] ) {
-		extended temp = extrema[1]; extrema[1] = extrema[0]; extrema[0]=temp;
+		xtended temp = extrema[1]; extrema[1] = extrema[0]; extrema[0]=temp;
 	    }
 	    if ( extrema[2]!=-999999 ) {
 		ecnt = 3;
 		if ( extrema[2]<extrema[0] ) {
-		    extended temp = extrema[2]; extrema[2] = extrema[0]; extrema[0]=temp;
+		    xtended temp = extrema[2]; extrema[2] = extrema[0]; extrema[0]=temp;
 		}
 		if ( extrema[2]<extrema[1] ) {
-		    extended temp = extrema[2]; extrema[2] = extrema[1]; extrema[1]=temp;
+		    xtended temp = extrema[2]; extrema[2] = extrema[1]; extrema[1]=temp;
 		}
 	    }
 	}
@@ -849,14 +849,14 @@ return( _CubicSolve(&sp,0,ts+1)+1);
     ecnt += 2;
     /* divide into monotonic sections & use binary search to find zeroes */
     for ( i=zcnt=0; i<ecnt-1; ++i ) {
-	extended top, bottom, val;
-	extended topt, bottomt, t;
+	xtended top, bottom, val;
+	xtended topt, bottomt, t;
 	topt = extrema[i+1];
 	bottomt = extrema[i];
 	top = (((q->a*topt+q->b)*topt+q->c)*topt+q->d)*topt+q->e;
 	bottom = (((q->a*bottomt+q->b)*bottomt+q->c)*bottomt+q->d)*bottomt+q->e;
 	if ( top<bottom ) {
-	    extended temp = top; top = bottom; bottom = temp;
+	    xtended temp = top; top = bottom; bottom = temp;
 	    temp = topt; topt = bottomt; bottomt = temp;
 	}
 	if ( bottom>.001 )	/* this monotonic is all above 0 */
