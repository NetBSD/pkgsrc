$NetBSD: patch-lib3d_ang3d.h,v 1.1 2011/11/25 21:50:31 joerg Exp $

--- lib3d/ang3d.h.orig	2011-11-25 15:13:08.000000000 +0000
+++ lib3d/ang3d.h
@@ -7,10 +7,11 @@
 #define ANG3D_h
 
 
-#include <iostream.h>
+#include <iostream>
 #include "general.h"
 #include "ang2d.h"
 
+using namespace std;
 
 struct ang3d
 { ang2d	xy,		// angle in XY plane
