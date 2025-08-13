$NetBSD: patch-src_libOpenImageIO_maketexture.cpp,v 1.2 2025/08/13 06:51:22 wiz Exp $

https://github.com/AcademySoftwareFoundation/OpenImageIO/pull/4857

--- src/libOpenImageIO/maketexture.cpp.orig	2025-08-13 06:21:04.554909439 +0000
+++ src/libOpenImageIO/maketexture.cpp
@@ -347,7 +347,7 @@ check_nan_block(const ImageBuf& src, ROI
         for (int x = x0; x < x1; ++x) {
             src.getpixel(x, y, pel);
             for (int c = 0; c < spec.nchannels; ++c) {
-                if (!isfinite(pel[c])) {
+                if (!std::isfinite(pel[c])) {
                     spin_lock lock(maketx_mutex);
                     // if (found_nonfinite < 3)
                     //     std::cerr << "maketx ERROR: Found " << pel[c]
