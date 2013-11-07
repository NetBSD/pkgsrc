$NetBSD: patch-knumber_knumber_float.cpp,v 1.2 2013/11/07 11:59:59 markd Exp $

use namespace std for isinf() and isnan()

--- knumber/knumber_float.cpp.orig	2013-03-01 07:05:02.000000000 +0000
+++ knumber/knumber_float.cpp
@@ -25,6 +25,8 @@ along with this program.  If not, see <h
 #include <QDebug>
 #include <math.h>
 
+using namespace std;
+
 // NOTE: these assume IEEE floats..
 #ifndef isinf
 #define isinf(x) ((x) != 0.0 && (x) + (x) == (x))
