$NetBSD: patch-font3d_geometry.h,v 1.1 2011/11/25 21:57:36 joerg Exp $

--- font3d/geometry.h.orig	2011-11-25 18:27:25.000000000 +0000
+++ font3d/geometry.h
@@ -31,7 +31,8 @@
 #ifndef __GEOMETRY_H__
 #define __GEOMETRY_H__
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 
 #include "vector.h"
 
