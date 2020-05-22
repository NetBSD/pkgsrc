$NetBSD: patch-pdf-dpi.cc,v 1.1 2020/05/22 01:15:34 joerg Exp $

--- pdf-dpi.cc.orig	2020-05-16 19:34:23.424498851 +0000
+++ pdf-dpi.cc
@@ -34,7 +34,7 @@ protected:
   }
 
   virtual void drawImage(pdf::gfx::State *state, pdf::Object *object, pdf::Stream *stream, int width, int height,
-    pdf::gfx::ImageColorMap *color_map, bool interpolate, int *mask_colors, bool inline_image)
+    pdf::gfx::ImageColorMap *color_map, bool interpolate, const int *mask_colors, bool inline_image)
   {
     this->process_image(state, width, height);
   }
