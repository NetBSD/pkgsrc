$NetBSD: patch-knumber_knumber_float.cpp,v 1.3 2014/02/01 02:20:49 markd Exp $

use namespace std for isinf() and isnan()

--- knumber/knumber_float.cpp.orig	2014-01-02 19:33:27.000000000 +0000
+++ knumber/knumber_float.cpp
@@ -25,6 +25,8 @@ along with this program.  If not, see <h
 #include <QDebug>
 #include <math.h>
 
+using namespace std;
+
 #ifdef _MSC_VER
 double log2(double x) { return log(x) / log(2); }
 double exp2(double x) { return exp(x * log(2)); }
