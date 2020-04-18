$NetBSD: patch-apps_visualisation_opencv__visualisation.cpp,v 1.1 2020/04/18 22:01:33 joerg Exp $

--- apps/visualisation/opencv_visualisation.cpp.orig	2020-04-18 02:44:25.906562998 +0000
+++ apps/visualisation/opencv_visualisation.cpp
@@ -60,6 +60,7 @@ Created by: Puttemans Steven - April 201
 
 #include <fstream>
 #include <iostream>
+#include <sstream>
 
 using namespace std;
 using namespace cv;
