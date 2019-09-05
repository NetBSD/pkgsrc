$NetBSD: patch-pdfium_core_fxcodec_codec_fx__codec__png.cpp,v 1.1 2019/09/05 08:07:25 nros Exp $
* use pkgsrc (system) libpng
--- pdfium/core/fxcodec/codec/fx_codec_png.cpp.orig	2019-08-10 09:07:09.000000000 +0000
+++ pdfium/core/fxcodec/codec/fx_codec_png.cpp
@@ -12,7 +12,7 @@
 
 extern "C" {
 #undef FAR
-#include "third_party/libpng16/png.h"
+#include <png.h>
 }
 
 static void _png_error_data(png_structp png_ptr, png_const_charp error_msg) {
