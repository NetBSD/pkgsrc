$NetBSD: patch-lib3d_pt2d.h,v 1.1 2011/11/25 21:50:31 joerg Exp $

--- lib3d/pt2d.h.orig	2011-11-25 15:12:01.000000000 +0000
+++ lib3d/pt2d.h
@@ -8,10 +8,11 @@
 
 
 #include <math.h>    // to get sqrt(), M_SQRT2, sin(), etc.
-#include <iostream.h>
+#include <iostream>
 #include "general.h"
 #include "ang2d.h"
 
+using namespace std;
 
 /*======================================================================*/
 struct pt2d {
