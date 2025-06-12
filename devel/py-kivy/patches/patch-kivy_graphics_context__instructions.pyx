$NetBSD: patch-kivy_graphics_context__instructions.pyx,v 1.1 2025/06/12 07:29:05 wiz Exp $

https://github.com/kivy/kivy/commit/5a1b27d7d3bdee6cedb55440bfae9c4e66fb3c68

--- kivy/graphics/context_instructions.pyx.orig	2024-12-26 16:04:18.000000000 +0000
+++ kivy/graphics/context_instructions.pyx
@@ -86,7 +86,7 @@ cdef tuple rgb_to_hsv(float r, float g, 
 
 cdef tuple hsv_to_rgb(float h, float s, float v):
     if s == 0.0: return v, v, v
-    cdef long i = long(h * 6.0)
+    cdef long i = <long>(h * 6.0)
     cdef float f = (h * <float>6.0) - i
     cdef float p = v * (<float>1.0 - s)
     cdef float q = v * (<float>1.0 - s * f)
