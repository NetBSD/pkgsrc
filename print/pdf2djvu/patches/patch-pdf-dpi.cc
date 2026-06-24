$NetBSD: patch-pdf-dpi.cc,v 1.3 2026/06/24 21:57:36 wiz Exp $

Fix build with poppler 26.06.
From Arch.
https://aur.archlinux.org/cgit/aur.git/plain/pdf2djvu-poppler-26.01.0.patch?h=pdf2djvu
https://aur.archlinux.org/cgit/aur.git/plain/pdf2djvu-poppler-26.x.patch?h=pdf2djvu

--- pdf-dpi.cc.orig	2022-08-09 20:28:01.000000000 +0000
+++ pdf-dpi.cc
@@ -91,7 +91,11 @@ void DpiGuessDevice::process_image(pdf::gfx::State *st
 
 void DpiGuessDevice::process_image(pdf::gfx::State *state, int width, int height)
 {
+#if POPPLER_VERSION > 260100
+  const std::array<double, 6> &ctm = state->getCTM();
+#else
   const double *ctm = state->getCTM();
+#endif
   double h_dpi = 72.0 * width / hypot(ctm[0], ctm[1]);
   double v_dpi = 72.0 * height / hypot(ctm[2], ctm[3]);
   this->min_ = std::min(this->min_, std::min(h_dpi, v_dpi));
