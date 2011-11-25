$NetBSD: patch-lib3d_pt3d.h,v 1.1 2011/11/25 21:50:31 joerg Exp $

--- lib3d/pt3d.h.orig	2011-11-25 15:13:38.000000000 +0000
+++ lib3d/pt3d.h
@@ -7,11 +7,12 @@
 #define PT3D_h
 
 
-#include <iostream.h>
+#include <iostream>
 #include "general.h"
 #include "pt2d.h"
 #include "ang3d.h"
 
+using namespace std;
 
 /*=========================================================================*/
 struct pt3d : pt2d {
