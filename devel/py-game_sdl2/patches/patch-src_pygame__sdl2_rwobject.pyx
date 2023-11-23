$NetBSD: patch-src_pygame__sdl2_rwobject.pyx,v 1.1 2023/11/23 15:39:05 ryoon Exp $

--- src/pygame_sdl2/rwobject.pyx.orig	2023-01-22 00:20:52.000000000 +0000
+++ src/pygame_sdl2/rwobject.pyx
@@ -64,7 +64,7 @@ cdef set_error(e):
     msg = <char *> e
     SDL_SetError("%s", msg)
 
-cdef Sint64 python_size(SDL_RWops *context) with gil:
+cdef Sint64 python_size(SDL_RWops *context) noexcept with gil:
     f = <object> context.hidden.unknown.data1
 
     try:
@@ -77,7 +77,7 @@ cdef Sint64 python_size(SDL_RWops *conte
 
     return rv
 
-cdef Sint64 python_seek(SDL_RWops *context, Sint64 seek, int whence) with gil:
+cdef Sint64 python_seek(SDL_RWops *context, Sint64 seek, int whence) noexcept with gil:
     f = <object> context.hidden.unknown.data1
 
     try:
@@ -89,7 +89,7 @@ cdef Sint64 python_seek(SDL_RWops *conte
 
     return rv
 
-cdef size_t python_read(SDL_RWops *context, void *ptr, size_t size, size_t maxnum) with gil:
+cdef size_t python_read(SDL_RWops *context, void *ptr, size_t size, size_t maxnum) noexcept with gil:
     f = <object> context.hidden.unknown.data1
 
     try:
@@ -101,7 +101,7 @@ cdef size_t python_read(SDL_RWops *conte
     memcpy(ptr, <void *><char *> data, len(data))
     return len(data)
 
-cdef size_t python_write(SDL_RWops *context, const void *ptr, size_t size, size_t maxnum) with gil:
+cdef size_t python_write(SDL_RWops *context, const void *ptr, size_t size, size_t maxnum) noexcept with gil:
     f = <object> context.hidden.unknown.data1
     data = (<char *> ptr)[:size * maxnum]
 
@@ -113,7 +113,7 @@ cdef size_t python_write(SDL_RWops *cont
 
     return len(data)
 
-cdef int python_close(SDL_RWops *context) with gil:
+cdef int python_close(SDL_RWops *context) noexcept with gil:
     if context != NULL:
         if context.hidden.unknown.data1 != NULL:
             f = <object> context.hidden.unknown.data1
@@ -136,11 +136,11 @@ cdef struct SubFile:
     Sint64 length
     Sint64 tell
 
-cdef Sint64 subfile_size(SDL_RWops *context) nogil:
+cdef Sint64 subfile_size(SDL_RWops *context) noexcept nogil:
     cdef SubFile *sf = <SubFile *> context.hidden.unknown.data1
     return sf.length
 
-cdef Sint64 subfile_seek(SDL_RWops *context, Sint64 seek, int whence) nogil:
+cdef Sint64 subfile_seek(SDL_RWops *context, Sint64 seek, int whence) noexcept nogil:
     cdef SubFile *sf = <SubFile *> context.hidden.unknown.data1
 
     if whence == RW_SEEK_SET:
@@ -152,7 +152,7 @@ cdef Sint64 subfile_seek(SDL_RWops *cont
 
     return sf.tell
 
-cdef size_t subfile_read(SDL_RWops *context, void *ptr, size_t size, size_t maxnum) nogil:
+cdef size_t subfile_read(SDL_RWops *context, void *ptr, size_t size, size_t maxnum) noexcept nogil:
     cdef SubFile *sf = <SubFile *> context.hidden.unknown.data1
 
     cdef Sint64 left = sf.length - sf.tell
@@ -171,7 +171,7 @@ cdef size_t subfile_read(SDL_RWops *cont
 
     return rv
 
-cdef int subfile_close(SDL_RWops *context) nogil:
+cdef int subfile_close(SDL_RWops *context) noexcept nogil:
     cdef SubFile *sf
 
     if context != NULL:
@@ -191,12 +191,12 @@ cdef struct BufFile:
     Uint8 *here
     Uint8 *stop
 
-cdef Sint64 buffile_size(SDL_RWops *context) nogil:
+cdef Sint64 buffile_size(SDL_RWops *context) noexcept nogil:
     cdef BufFile *bf = <BufFile *> context.hidden.unknown.data1
 
     return bf.stop - bf.base
 
-cdef Sint64 buffile_seek(SDL_RWops *context, Sint64 offset, int whence) nogil:
+cdef Sint64 buffile_seek(SDL_RWops *context, Sint64 offset, int whence) noexcept nogil:
     cdef BufFile *bf = <BufFile *> context.hidden.unknown.data1
 
     cdef Uint8 *newpos
@@ -219,7 +219,7 @@ cdef Sint64 buffile_seek(SDL_RWops *cont
 
     return bf.here - bf.base
 
-cdef size_t buffile_read(SDL_RWops *context, void *ptr, size_t size, size_t maxnum) nogil:
+cdef size_t buffile_read(SDL_RWops *context, void *ptr, size_t size, size_t maxnum) noexcept nogil:
     cdef BufFile *bf = <BufFile *> context.hidden.unknown.data1
     cdef size_t total_bytes = 0
     cdef size_t mem_available = 0
@@ -237,7 +237,7 @@ cdef size_t buffile_read(SDL_RWops *cont
 
     return (total_bytes // size)
 
-cdef size_t buffile_write(SDL_RWops *context, const void *ptr, size_t size, size_t num) nogil:
+cdef size_t buffile_write(SDL_RWops *context, const void *ptr, size_t size, size_t num) noexcept nogil:
     cdef BufFile *bf = <BufFile *> context.hidden.unknown.data1
 
     if bf.view.readonly != 0:
@@ -250,7 +250,7 @@ cdef size_t buffile_write(SDL_RWops *con
 
     return num
 
-cdef int buffile_close(SDL_RWops *context) with gil:
+cdef int buffile_close(SDL_RWops *context) noexcept with gil:
     cdef BufFile *bf
 
     if context != NULL:
