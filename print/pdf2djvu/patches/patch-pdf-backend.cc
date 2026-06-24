$NetBSD: patch-pdf-backend.cc,v 1.8 2026/06/24 21:57:36 wiz Exp $

Fix build with poppler 26.06.
From Arch.
https://aur.archlinux.org/cgit/aur.git/plain/pdf2djvu-poppler-26.01.0.patch?h=pdf2djvu
https://aur.archlinux.org/cgit/aur.git/plain/pdf2djvu-poppler-26.x.patch?h=pdf2djvu

Second chunk was added locally, also needed.

--- pdf-backend.cc.orig	2022-08-09 20:28:01.000000000 +0000
+++ pdf-backend.cc
@@ -163,7 +163,7 @@ static void cmyk_to_rgb(const double cmyk[], double rg
   pdf::gfx::RgbColor rgb_cc;
   for (int i = 0; i < 4; i++)
     cmyk_cc.c[i] = pdf::gfx::double_as_color_component(cmyk[i]);
-  cmyk_space.getRGB(&cmyk_cc, &rgb_cc);
+  cmyk_space.getRGB(cmyk_cc, &rgb_cc);
   rgb[0] = pdf::gfx::color_component_as_double(rgb_cc.r);
   rgb[1] = pdf::gfx::color_component_as_double(rgb_cc.g);
   rgb[2] = pdf::gfx::color_component_as_double(rgb_cc.b);
@@ -175,13 +175,13 @@ static bool annotations_callback(pdf::ant::Annotation 
   std::string border_color;
   if (annotation->getType() != pdf::ant::Annotation::typeLink)
     return true;
-  pdf::ant::Color *color = annotation->getColor();
+  const AnnotColor* color = annotation->getColor();
   if (color == nullptr)
   {
     border_colors.push_back("");
     return true;
   }
-  const double *values = color->getValues();
+  const double *values = color->getValues().data();
   switch (color->getSpace())
   {
   case pdf::ant::Color::colorTransparent:
@@ -407,7 +407,11 @@ pdf::Metadata::Metadata(pdf::Document &document)
     char tzs = 0; int tzh = 0, tzm = 0;
     if (!pdf::dict_lookup(info_dict, field.first, &object)->isString())
       continue;
+#if POPPLER_VERSION > 260300
+    const char *input = object.getString().c_str();
+#else
     const char *input = pdf::get_c_string(object.getString());
+#endif
     if (input[0] == 'D' && input[1] == ':')
       input += 2;
     int year = scan_date_digits(input, 4);
@@ -470,7 +474,11 @@ pdf::Renderer::Renderer(pdf::splash::Color &paper_colo
 bool pdf::Environment::antialias = false;
 
 pdf::Renderer::Renderer(pdf::splash::Color &paper_color, bool monochrome)
+#if POPPLER_VERSION > 260100
+: pdf::splash::OutputDevice(monochrome ? splashModeMono1 : splashModeRGB8, 4, paper_color),
+#else
 : pdf::splash::OutputDevice(monochrome ? splashModeMono1 : splashModeRGB8, 4, false, paper_color),
+#endif
   catalog(NULL)
 {
   this->setFontAntialias(pdf::Environment::antialias);
@@ -499,7 +507,12 @@ bool pdf::get_glyph(splash::Splash *splash, splash::Fo
   if (font == nullptr)
     return false;
   splash::ClipResult clip_result;
+#if POPPLER_VERSION > 251200 && POPPLER_VERSION < 260100
+  const SplashClip* clip_ptr = const_cast<SplashClip*>(&splash->getClip());
+  if (!font->getGlyph(code, 0, 0, bitmap, static_cast<int>(x), static_cast<int>(y), clip_ptr, &clip_result))
+#else
   if (!font->getGlyph(code, 0, 0, bitmap, static_cast<int>(x), static_cast<int>(y), splash->getClip(), &clip_result))
+#endif
     return false;
   return (clip_result != splashClipAllOutside);
 }
@@ -525,7 +538,11 @@ void pdf::Renderer::convert_path(pdf::gfx::State *stat
     {
       double x1, y1, x2, y2, x3, y3;
       state->transform(subpath->getX(0), subpath->getY(0), &x1, &y1);
+#if POPPLER_VERSION > 260400
+      splash_path.moveTo(x1, y1);
+#else
       splash_path.moveTo(static_cast<splash::Coord>(x1), static_cast<splash::Coord>(y1));
+#endif
       int j = 1;
       int n_points = subpath->getNumPoints();
       while (j < n_points)
@@ -535,17 +552,25 @@ void pdf::Renderer::convert_path(pdf::gfx::State *stat
           state->transform(subpath->getX(j), subpath->getY(j), &x1, &y1);
           state->transform(subpath->getX(j + 1), subpath->getY(j + 1), &x2, &y2);
           state->transform(subpath->getX(j + 2), subpath->getY(j + 2), &x3, &y3);
+#if POPPLER_VERSION > 260400
+          splash_path.curveTo(x1, y1, x2, y2, x3, y3);
+#else
           splash_path.curveTo(
             static_cast<splash::Coord>(x1), static_cast<splash::Coord>(y1),
             static_cast<splash::Coord>(x2), static_cast<splash::Coord>(y2),
             static_cast<splash::Coord>(x3), static_cast<splash::Coord>(y3)
           );
+#endif
           j += 3;
         }
         else
         {
           state->transform(subpath->getX(j), subpath->getY(j), &x1, &y1);
+#if POPPLER_VERSION > 260400
+          splash_path.lineTo(x1, y1);
+#else
           splash_path.lineTo(static_cast<splash::Coord>(x1), static_cast<splash::Coord>(y1));
+#endif
           j++;
         }
       }
