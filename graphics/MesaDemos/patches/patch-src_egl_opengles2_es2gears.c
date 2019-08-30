$NetBSD: patch-src_egl_opengles2_es2gears.c,v 1.1 2019/08/30 17:12:19 nia Exp $

sincos is a GNU extension.

--- src/egl/opengles2/es2gears.c.orig	2018-02-23 08:50:21.000000000 +0000
+++ src/egl/opengles2/es2gears.c
@@ -55,6 +55,8 @@
 #define VERTICES_PER_TOOTH 34
 #define GEAR_VERTEX_STRIDE 6
 
+#define sincos(x, sinp, cosp) *sinp = sin(x); *cosp = cos(x);
+
 /**
  * Struct describing the vertices in triangle strip
  */
