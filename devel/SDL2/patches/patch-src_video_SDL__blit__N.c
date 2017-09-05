$NetBSD: patch-src_video_SDL__blit__N.c,v 1.1 2017/09/05 09:02:18 he Exp $

Put code after declarations.

--- src/video/SDL_blit_N.c.orig	2016-10-20 03:56:26.000000000 +0000
+++ src/video/SDL_blit_N.c
@@ -118,12 +118,6 @@ calc_swizzle32(const SDL_PixelFormat * s
         16, 8, 0, 24,
         0, NULL
     };
-    if (!srcfmt) {
-        srcfmt = &default_pixel_format;
-    }
-    if (!dstfmt) {
-        dstfmt = &default_pixel_format;
-    }
     const vector unsigned char plus = VECUINT8_LITERAL(0x00, 0x00, 0x00, 0x00,
                                                        0x04, 0x04, 0x04, 0x04,
                                                        0x08, 0x08, 0x08, 0x08,
@@ -136,6 +130,13 @@ calc_swizzle32(const SDL_PixelFormat * s
     Uint32 gmask = RESHIFT(srcfmt->Gshift) << (dstfmt->Gshift);
     Uint32 bmask = RESHIFT(srcfmt->Bshift) << (dstfmt->Bshift);
     Uint32 amask;
+
+    if (!srcfmt) {
+        srcfmt = &default_pixel_format;
+    }
+    if (!dstfmt) {
+        dstfmt = &default_pixel_format;
+    }
     /* Use zero for alpha if either surface doesn't have alpha */
     if (dstfmt->Amask) {
         amask =
