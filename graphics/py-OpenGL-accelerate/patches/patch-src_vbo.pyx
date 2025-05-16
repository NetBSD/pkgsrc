$NetBSD: patch-src_vbo.pyx,v 1.1 2025/05/16 14:47:23 adam Exp $

Fix for Cython 3.1.

--- src/vbo.pyx.orig	2025-05-16 14:44:59.989869473 +0000
+++ src/vbo.pyx
@@ -188,7 +188,7 @@ cdef class VBO:
         assert not self.created, """Already created the buffer"""
         buffers = self.get_implementation().glGenBuffers(1)
         try:
-            self.buffer = long( buffers )
+            self.buffer = int( buffers )
         except (TypeError,ValueError) as err:
             self.buffer = buffers[0]
         self.target = self.c_resolve( self.target_spec )
@@ -242,7 +242,7 @@ cdef class VBO:
         """Add an integer to this VBO (offset)"""
         if hasattr( other, 'offset' ):
             other = other.offset
-        assert isinstance( other, (int,long) ), """Only know how to add integer/long offsets"""
+        assert isinstance( other, int ), """Only know how to add integer/long offsets"""
         return VBOOffset( self, other )
     cdef int check_live( self ):
         if self.data is _NULL:
