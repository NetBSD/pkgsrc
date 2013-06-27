$NetBSD: patch-library_canvas_src_mdc__draw__util.cpp,v 1.1 2013/06/27 15:48:42 joerg Exp $

--- library/canvas/src/mdc_draw_util.cpp.orig	2013-06-27 14:43:37.000000000 +0000
+++ library/canvas/src/mdc_draw_util.cpp
@@ -19,6 +19,7 @@
 
 #include "stdafx.h"
 
+#include <cstdlib>
 #ifndef _WIN32
 #include <string.h>
 #endif
