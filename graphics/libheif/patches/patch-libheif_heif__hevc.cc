$NetBSD: patch-libheif_heif__hevc.cc,v 1.1 2020/10/02 17:09:35 otis Exp $

Help the compiler find the prototype fow pow()

--- libheif/heif_hevc.cc.orig	2020-09-22 10:09:51.000000000 +0000
+++ libheif/heif_hevc.cc
@@ -21,6 +21,8 @@
 #include "heif_hevc.h"
 #include "bitstream.h"
 
+#include <math.h>
+
 #include <cmath>
 
 using namespace heif;
