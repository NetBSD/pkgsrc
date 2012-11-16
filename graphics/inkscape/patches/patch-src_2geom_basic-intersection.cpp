$NetBSD: patch-src_2geom_basic-intersection.cpp,v 1.1 2012/11/16 00:54:04 joerg Exp $

--- src/2geom/basic-intersection.cpp.orig	2012-11-15 17:34:38.000000000 +0000
+++ src/2geom/basic-intersection.cpp
@@ -64,24 +64,27 @@ void find_intersections(std::vector< std
 void split(vector<Point> const &p, double t, 
            vector<Point> &left, vector<Point> &right) {
     const unsigned sz = p.size();
-    Geom::Point Vtemp[sz][sz];
+    Geom::Point *Vtemp = new Geom::Point[sz * sz];;
 
     /* Copy control points	*/
-    std::copy(p.begin(), p.end(), Vtemp[0]);
+    for (unsigned i = 0; i < sz; ++i)
+        Vtemp[0 * sz + i] = p[i];
 
     /* Triangle computation	*/
     for (unsigned i = 1; i < sz; i++) {
         for (unsigned j = 0; j < sz - i; j++) {
-            Vtemp[i][j] = lerp(t, Vtemp[i-1][j], Vtemp[i-1][j+1]);
+            Vtemp[i * sz + j] = lerp(t, Vtemp[(i-1) * sz + j], Vtemp[(i-1) * sz + j+1]);
         }
     }
 
     left.resize(sz);
     right.resize(sz);
     for (unsigned j = 0; j < sz; j++)
-        left[j]  = Vtemp[j][0];
+        left[j]  = Vtemp[j * sz];
     for (unsigned j = 0; j < sz; j++)
-        right[j] = Vtemp[sz-1-j][j];
+        right[j] = Vtemp[(sz-1-j) * sz + j];
+
+    delete[] Vtemp;
 }
 
 
