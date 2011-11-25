$NetBSD: patch-lib3d_region3d.h,v 1.1 2011/11/25 21:50:31 joerg Exp $

--- lib3d/region3d.h.orig	2011-11-25 15:14:54.000000000 +0000
+++ lib3d/region3d.h
@@ -7,8 +7,8 @@
 #define REGION3D_h
 
 
-#include <iostream.h>
-#include <list.h>   // STL
+#include <iostream>
+#include <list>   // STL
 #include "general.h"
 #include "xform.h"
 #include "region2d.h"
@@ -18,6 +18,7 @@
 #include "edgetable.h"
 #include "xpanel3d.h"
 
+using namespace std;
 
 extern const pt3d::coord COORD_MAX;
 
