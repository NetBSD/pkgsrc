$NetBSD: patch-pdfium_core_fxcodec_codec_fx__codec__icc.cpp,v 1.1 2023/09/09 09:49:56 nros Exp $

Use pkgsrc lcms2

--- pdfium/core/fxcodec/codec/fx_codec_icc.cpp.orig	2023-09-08 16:30:26.678351870 +0000
+++ pdfium/core/fxcodec/codec/fx_codec_icc.cpp
@@ -6,7 +6,7 @@
 
 #include "core/fxcodec/codec/codec_int.h"
 #include "core/fxcodec/fx_codec.h"
-#include "third_party/lcms/include/lcms2.h"
+#include <lcms2.h>
 
 const uint32_t N_COMPONENT_LAB = 3;
 const uint32_t N_COMPONENT_GRAY = 1;
