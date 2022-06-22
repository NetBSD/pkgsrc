$NetBSD: patch-libuna_libuna__inline.h,v 1.1 2022/06/22 10:29:02 wiz Exp $

Avoid using inline, leads to missing symbols like this

ld: ../libcsystem/.libs/libcsystem.a(libuna_byte_stream.o): in function `libuna_byte_stream_size_from_utf8':
libuna_byte_stream.c:(.text+0x81): undefined reference to `libuna_unicode_character_copy_from_utf8'

on at least NetBSD 9 and 9.99 with default compiler (gcc).


--- libuna/libuna_inline.h.orig	2015-01-25 07:30:04.000000000 +0000
+++ libuna/libuna_inline.h
@@ -31,7 +31,7 @@
 #define LIBUNA_INLINE /* inline */
 
 #else
-#define LIBUNA_INLINE inline
+#define LIBUNA_INLINE /* inline */
 
 #endif
 
