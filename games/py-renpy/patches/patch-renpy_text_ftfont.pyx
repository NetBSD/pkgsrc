$NetBSD: patch-renpy_text_ftfont.pyx,v 1.1 2023/11/23 15:41:21 ryoon Exp $

--- renpy/text/ftfont.pyx.orig	2023-11-21 07:29:03.272598441 +0000
+++ renpy/text/ftfont.pyx
@@ -120,7 +120,7 @@ cdef bint is_zerowidth(unsigned int char
 
     return False
 
-cdef unsigned long io_func(FT_Stream stream, unsigned long offset, unsigned char *buffer, unsigned long count):
+cdef unsigned long io_func(FT_Stream stream, unsigned long offset, unsigned char *buffer, unsigned long count) noexcept:
     """
     Seeks to offset, and then reads count bytes from the stream into buffer.
     """
@@ -157,7 +157,7 @@ cdef unsigned long io_func(FT_Stream str
 
     return count
 
-cdef void close_func(FT_Stream stream):
+cdef void close_func(FT_Stream stream) noexcept:
     """
     Close the stream.
 
