$NetBSD: patch-src_guess.cpp,v 1.1 2015/06/10 15:00:31 joerg Exp $

--- src/guess.cpp.orig	2011-02-08 09:29:00.000000000 +0000
+++ src/guess.cpp
@@ -15,11 +15,10 @@
 #include "settings.h"
 
 using namespace std;
-using boost::array;
 
-const array<string, 3> Guess::linear_traits =
+const boost::array<string, 3> Guess::linear_traits =
                                     {{ "slope", "intercept", "avgy" }};
-const array<string, 4> Guess::peak_traits =
+const boost::array<string, 4> Guess::peak_traits =
                                     {{ "center", "height", "hwhm", "area" }};
 
 Guess::Guess(Settings const *settings) : settings_(settings)
@@ -97,7 +96,7 @@ double Guess::find_hwhm(int pos, double*
 
 // outputs vector with: center, height, hwhm, area
 // returns values corresponding to peak_traits
-array<double,4> Guess::estimate_peak_parameters()
+boost::array<double,4> Guess::estimate_peak_parameters()
 {
     // find the highest point, which must be higher than the previous and next
     // points (-> it cannot be the first/last point)
@@ -112,11 +111,11 @@ array<double,4> Guess::estimate_peak_par
     double center = xx_[pos];
     double area;
     double hwhm = find_hwhm(pos, &area) * settings_->width_correction;
-    array<double,4> r = {{ center, height, hwhm, area }};
+    boost::array<double,4> r = {{ center, height, hwhm, area }};
     return r;
 }
 
-array<double,3> Guess::estimate_linear_parameters()
+boost::array<double,3> Guess::estimate_linear_parameters()
 {
     double sx = 0, sy = 0, sxx = 0, syy = 0, sxy = 0;
     int n = yy_.size();
@@ -132,7 +131,7 @@ array<double,3> Guess::estimate_linear_p
     double slope = (n * sxy - sx * sy) / (n * sxx - sx * sx);
     double intercept = (sy - slope * sx) / n;
     double avgy = sy / n;
-    array<double,3> r = {{ slope, intercept, avgy }};
+    boost::array<double,3> r = {{ slope, intercept, avgy }};
     return r;
 }
 
