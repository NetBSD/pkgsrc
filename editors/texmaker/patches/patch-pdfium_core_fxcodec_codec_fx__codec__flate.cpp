$NetBSD: patch-pdfium_core_fxcodec_codec_fx__codec__flate.cpp,v 1.1 2023/09/09 09:49:56 nros Exp $

Use pkgsrc zlib

--- pdfium/core/fxcodec/codec/fx_codec_flate.cpp.orig	2023-09-08 18:32:51.006233364 +0000
+++ pdfium/core/fxcodec/codec/fx_codec_flate.cpp
@@ -11,7 +11,7 @@
 
 #include "core/fxcodec/fx_codec.h"
 #include "core/fxcrt/fx_ext.h"
-#include "third_party/zlib_v128/zlib.h"
+#include <zlib.h>
 
 extern "C" {
 static void* my_alloc_func(void* opaque,
