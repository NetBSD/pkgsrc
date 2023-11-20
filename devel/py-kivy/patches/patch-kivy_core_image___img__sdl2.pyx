$NetBSD: patch-kivy_core_image___img__sdl2.pyx,v 1.1 2023/11/20 06:36:47 wiz Exp $

https://github.com/kivy/kivy/pull/8326/files

--- kivy/core/image/_img_sdl2.pyx.orig	2023-11-20 06:24:23.659161661 +0000
+++ kivy/core/image/_img_sdl2.pyx
@@ -14,14 +14,14 @@ cdef struct SDL_RWops:
     int (* close) (SDL_RWops * context)
 
 
-cdef size_t rwops_bytesio_write(SDL_RWops *context, const void *ptr, size_t size, size_t num):
+cdef size_t rwops_bytesio_write(SDL_RWops *context, const void *ptr, size_t size, size_t num) noexcept:
     cdef char *c_string = <char *>ptr
     byteio = <object>context.hidden.unknown.data1
     byteio.write(c_string[:size * num])
     return size * num
 
 
-cdef int rwops_bytesio_close(SDL_RWops *context):
+cdef int rwops_bytesio_close(SDL_RWops *context) noexcept:
     byteio = <object>context.hidden.unknown.data1
     byteio.seek(0)
 
