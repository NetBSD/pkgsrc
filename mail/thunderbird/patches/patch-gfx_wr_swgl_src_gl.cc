$NetBSD: patch-gfx_wr_swgl_src_gl.cc,v 1.1 2026/08/30 10:26:05 ryoon Exp $

* Use cmath for C++ to avoid errors under NetBSD.

--- gfx/wr/swgl/src/gl.cc.orig	2026-08-14 14:46:45.531876235 +0000
+++ gfx/wr/swgl/src/gl.cc
@@ -7,7 +7,7 @@
 #include <string.h>
 #include <assert.h>
 #include <stdio.h>
-#include <math.h>
+#include <cmath>
 
 #ifdef __MACH__
 #  include <mach/mach.h>
