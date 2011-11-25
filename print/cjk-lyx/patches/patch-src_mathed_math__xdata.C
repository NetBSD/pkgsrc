$NetBSD: patch-src_mathed_math__xdata.C,v 1.1 2011/11/25 22:16:26 joerg Exp $

--- src/mathed/math_xdata.C.orig	2011-11-25 17:01:56.000000000 +0000
+++ src/mathed/math_xdata.C
@@ -9,7 +9,7 @@
 #include "Painter.h"
 #include "textpainter.h"
 #include "debug.h"
-
+#include <cstdlib>
 
 using std::max;
 using std::min;
