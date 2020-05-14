$NetBSD: patch-font3d_geometry.cc,v 1.2 2020/05/14 19:27:41 joerg Exp $

--- font3d/geometry.cc.orig	2000-07-16 02:37:31.000000000 +0000
+++ font3d/geometry.cc
@@ -31,11 +31,12 @@
 #include <math.h>
 #include <stddef.h>
 #include <stdio.h>
-#include <iostream.h>
+#include <iostream>
 
 #include "vector.h"
 #include "geometry.h"
 
+using std::endl, std::cout;
 
 //==============================================================================================
 //  TRIANGLELIST::Empty()                                                             (PUBLIC)
