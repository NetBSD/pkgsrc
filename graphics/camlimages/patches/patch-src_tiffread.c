$NetBSD: patch-src_tiffread.c,v 1.2 2012/07/29 12:52:55 marino Exp $

Both ocaml/caml/config.h and tiff.h define int32, uint32, etc.
The workaround of this name polution is to intentionally overwrite the
first caml definition with a garbage macro before tiff.h is included and
then unset it after the include.  After tiff version 4.0.1, the same hack
has to be applied to 64-bit types.  Unlike tiffwrite.c, tiffread.c forgot
to unset the bogus definitions.  The uint16 and uint32 then has to be
redefined correctly.  (ugly hack)

--- src/tiffread.c.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/tiffread.c
@@ -28,9 +28,20 @@
 #define uint16 uint16tiff
 #define int32 int32tiff
 #define uint32 uint32tiff
+#define int64 int64tiff
+#define uint64 uint64tiff
 
 #include <tiffio.h>
 
+#undef int16
+#undef uint16
+#undef int32
+#undef uint32
+#undef int64
+#undef uint64
+#define uint16 uint16_t
+#define uint32 uint32_t
+
 extern value *imglib_error;
 
 value open_tiff_file_for_read( name )
