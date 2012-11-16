$NetBSD: patch-src_2geom_solve-bezier-parametric.cpp,v 1.1 2012/11/16 00:54:04 joerg Exp $

--- src/2geom/solve-bezier-parametric.cpp.orig	2012-11-15 17:42:23.000000000 +0000
+++ src/2geom/solve-bezier-parametric.cpp
@@ -191,24 +191,27 @@ Bezier(Geom::Point const *V, /* Control 
        Geom::Point *Left,	/* RETURN left half ctl pts */
        Geom::Point *Right)	/* RETURN right half ctl pts */
 {
-    Geom::Point Vtemp[degree+1][degree+1];
+    const unsigned sz = degree + 1;
+    Geom::Point *Vtemp = new Geom::Point[sz * sz];
 
     /* Copy control points	*/
-    std::copy(V, V+degree+1, Vtemp[0]);
+    for (unsigned i = 0; i < sz; ++i)
+        Vtemp[0 * sz + i] = V[i];
 
     /* Triangle computation	*/
     for (unsigned i = 1; i <= degree; i++) {	
         for (unsigned j = 0; j <= degree - i; j++) {
-            Vtemp[i][j] = lerp(t, Vtemp[i-1][j], Vtemp[i-1][j+1]);
+            Vtemp[i * sz + j] = lerp(t, Vtemp[(i-1) * sz + j], Vtemp[(i-1) * sz + j+1]);
         }
     }
     
     for (unsigned j = 0; j <= degree; j++)
-        Left[j]  = Vtemp[j][0];
+        Left[j]  = Vtemp[j * sz + 0];
     for (unsigned j = 0; j <= degree; j++)
-        Right[j] = Vtemp[degree-j][j];
-
-    return (Vtemp[degree][0]);
+        Right[j] = Vtemp[(degree-j) * sz + j];
+    Geom::Point rv(Vtemp[degree * sz + 0]);
+    delete[] Vtemp;
+    return rv;
 }
 
 };
