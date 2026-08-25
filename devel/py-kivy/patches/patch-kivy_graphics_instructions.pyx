$NetBSD: patch-kivy_graphics_instructions.pyx,v 1.1 2026/08/25 09:23:01 wiz Exp $

Fix build with cython 3.3.0.

--- kivy/graphics/instructions.pyx.orig	2026-08-25 09:19:15.547250579 +0000
+++ kivy/graphics/instructions.pyx
@@ -895,10 +895,7 @@ cdef class RenderContext(Canvas):
 
     cdef int apply(self) except -1:
         cdef list keys
-        if PY2:
-            keys = self.state_stacks.keys()
-        else:
-            keys = list(self.state_stacks.keys())
+        keys = list(self.state_stacks.keys())
 
         cdef RenderContext active_context = getActiveContext()
         if self._use_parent_projection:
