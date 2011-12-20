$NetBSD: patch-src_AM_ROSAM.cpp,v 1.1 2011/12/20 13:42:47 wiz Exp $

Add missing header.

--- src/AM/ROSAM.cpp.orig	2006-09-20 15:01:44.000000000 +0000
+++ src/AM/ROSAM.cpp
@@ -30,6 +30,7 @@
  */
 //#include <iostream>
 #include <fstream>
+#include <stdlib.h>
 #include <sstream>
 #include <strstream>
 
