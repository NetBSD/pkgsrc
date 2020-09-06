$NetBSD: patch-examples_encoder__png.cc,v 1.1 2020/09/06 07:18:32 tnn Exp $

stdlib.h for malloc/free

--- examples/encoder_png.cc.orig	2020-08-13 16:57:45.000000000 +0000
+++ examples/encoder_png.cc
@@ -28,6 +28,7 @@
 #include <math.h>
 #include <png.h>
 #include <string.h>
+#include <stdlib.h>
 
 #include "encoder_png.h"
 
