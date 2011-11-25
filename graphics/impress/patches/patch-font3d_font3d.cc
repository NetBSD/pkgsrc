$NetBSD: patch-font3d_font3d.cc,v 1.1 2011/11/25 21:57:36 joerg Exp $

--- font3d/font3d.cc.orig	2011-11-25 18:27:38.000000000 +0000
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
 
