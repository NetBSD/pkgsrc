$NetBSD: patch-Source_Utils_ImageIO.cpp,v 1.1 2019/06/13 13:04:02 nia Exp $

Include missing header.

--- Source/Utils/ImageIO.cpp.orig	2018-09-22 22:25:29.948457285 -0700
+++ Source/Utils/ImageIO.cpp	2018-09-22 22:25:37.654043234 -0700
@@ -26,6 +26,7 @@
 #include <jpeglib.h>
 #include <png.h>
 #include <stdio.h>
+#include <unistd.h>
 #include <zlib.h>
 
 /* These two are needed for screenshot */
