$NetBSD: patch-src_cairo__ocaml__types.h,v 1.1 2024/02/14 15:59:56 wiz Exp $

Use standard freetype header include path.

--- src/cairo_ocaml_types.h.orig	2024-02-14 15:57:51.311904614 +0000
+++ src/cairo_ocaml_types.h
@@ -335,7 +335,7 @@ DEFINE_CUSTOM_OPERATIONS(scaled_font,
 
 #ifdef OCAML_CAIRO_HAS_FT
 #include <cairo-ft.h>
-#include <ftmodapi.h>
+#include <freetype/ftmodapi.h>
 
 #define FT_LIBRARY_ASSIGN(v, x) \
   v = ALLOC(cairo_ft_library);  FT_LIBRARY_VAL(v) = x
