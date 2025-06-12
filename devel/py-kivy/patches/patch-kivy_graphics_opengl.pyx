$NetBSD: patch-kivy_graphics_opengl.pyx,v 1.1 2025/06/12 07:29:05 wiz Exp $

https://github.com/kivy/kivy/commit/5a1b27d7d3bdee6cedb55440bfae9c4e66fb3c68

--- kivy/graphics/opengl.pyx.orig	2024-12-26 16:04:18.000000000 +0000
+++ kivy/graphics/opengl.pyx
@@ -689,7 +689,7 @@ def glDrawElements(GLenum mode, GLsizei 
     cdef void *ptr = NULL
     if isinstance(indices, bytes):
         ptr = <void *>(<char *>(<bytes>indices))
-    elif isinstance(indices, (long, int)):
+    elif isinstance(indices, int):
         ptr = <void *>(<unsigned int>indices)
     else:
         raise TypeError("Argument 'indices' has incorrect type (expected bytes or int).")
@@ -1539,7 +1539,7 @@ def glVertexAttribPointer(GLuint index, 
     cdef void *ptr = NULL
     if isinstance(data, bytes):
         ptr = <void *>(<char *>(<bytes>data))
-    elif isinstance(data, (long, int)):
+    elif isinstance(data, int):
         ptr = <void *>(<unsigned int>data)
     else:
         raise TypeError("Argument 'data' has incorrect type (expected bytes or int).")
