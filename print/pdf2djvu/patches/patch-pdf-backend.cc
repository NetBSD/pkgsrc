$NetBSD: patch-pdf-backend.cc,v 1.4 2020/05/22 01:15:34 joerg Exp $

--- pdf-backend.cc.orig	2020-05-16 19:37:30.700296649 +0000
+++ pdf-backend.cc
@@ -48,7 +48,7 @@
  * ======================
  */
 
-static void poppler_error_handler(void *data, ErrorCategory category, pdf::Offset pos, const char *message)
+static void poppler_error_handler(ErrorCategory category, pdf::Offset pos, const char *message)
 {
   std::string format;
   const char *category_name = _("PDF error");
@@ -103,8 +103,8 @@ static void poppler_error_handler(void *
 
 pdf::Environment::Environment()
 {
-  globalParams = new GlobalParams();
-  setErrorCallback(poppler_error_handler, nullptr);
+  globalParams.reset(new GlobalParams());
+  setErrorCallback(poppler_error_handler);
 }
 
 void pdf::Environment::set_antialias(bool value)
@@ -499,8 +499,8 @@ bool pdf::get_glyph(splash::Splash *spla
 void pdf::Renderer::convert_path(pdf::gfx::State *state, splash::Path &splash_path)
 {
   /* Source was copied from <poppler/SplashOutputDev.c>. */
-  pdf::gfx::Subpath *subpath;
-  pdf::gfx::Path *path = state->getPath();
+  const pdf::gfx::Subpath *subpath;
+  const pdf::gfx::Path *path = state->getPath();
   int n_subpaths = path->getNumSubpaths();
   for (int i = 0; i < n_subpaths; i++)
   {
