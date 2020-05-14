$NetBSD: patch-font3d_font3d.cc,v 1.2 2020/05/14 19:27:41 joerg Exp $

--- font3d/font3d.cc.orig	2000-07-16 02:37:31.000000000 +0000
+++ font3d/font3d.cc
@@ -30,8 +30,8 @@
 
 #include <math.h>
 #include <stdlib.h>
-#include <iostream.h>
-#include <iomanip.h>
+#include <iostream>
+#include <iomanip>
 #include <stdio.h>
 #include <string.h>
 
@@ -39,6 +39,7 @@
 #include "build.h"
 #include "font3d.h"
 
+using std::ios, std::ofstream, std::setprecision, std::ifstream, std::endl, std::cout;
 
 //==============================================================================================
 //  PrintGreeting()
