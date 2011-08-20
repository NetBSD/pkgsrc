$NetBSD: patch-ofxconnect_ofxconnect.cpp,v 1.1 2011/08/20 19:25:39 wiz Exp $

Fix build with gcc-4.5.

--- ofxconnect/ofxconnect.cpp.orig	2007-01-09 08:04:37.000000000 +0000
+++ ofxconnect/ofxconnect.cpp
@@ -28,6 +28,8 @@
  *   (at your option) any later version.                                   *
  *                                                                         *
  ***************************************************************************/
+#include <cstdlib>
+#include <cstring>
 #include <iostream>
 #include <fstream>
 #include <string>
