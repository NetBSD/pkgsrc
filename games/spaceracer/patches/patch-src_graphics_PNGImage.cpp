$NetBSD: patch-src_graphics_PNGImage.cpp,v 1.1 2013/03/02 18:10:43 joerg Exp $

--- src/graphics/PNGImage.cpp.orig	2013-03-01 21:58:51.000000000 +0000
+++ src/graphics/PNGImage.cpp
@@ -16,6 +16,7 @@
 
 #include "PNGImage.h"
 #include  <stdlib.h>
+#include <string.h>
 
 PNGImage::PNGImage(char *filename)
 {
