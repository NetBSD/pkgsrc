$NetBSD: patch-pdfium_core_fxcodec_codec_fx__codec__jpx__opj.cpp,v 1.1 2023/09/09 09:49:56 nros Exp $

use pkgsrc lcms2

--- pdfium/core/fxcodec/codec/fx_codec_jpx_opj.cpp.orig	2023-09-08 16:31:13.446248295 +0000
+++ pdfium/core/fxcodec/codec/fx_codec_jpx_opj.cpp
@@ -13,7 +13,7 @@
 #include "core/fxcodec/fx_codec.h"
 #include "core/fxcrt/fx_memory.h"
 #include "core/fxcrt/fx_safe_types.h"
-#include "third_party/lcms/include/lcms2.h"
+#include <lcms2.h>
 #include "third_party/libopenjpeg20/openjpeg.h"
 #include "third_party/libopenjpeg20/opj_malloc.h"
 
