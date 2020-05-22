$NetBSD: patch-pdf2djvu.cc,v 1.4 2020/05/22 01:15:34 joerg Exp $

--- pdf2djvu.cc.orig	2019-06-10 17:06:44.000000000 +0000
+++ pdf2djvu.cc
@@ -81,7 +81,7 @@ static int get_page_for_goto_link(pdf::l
 #endif
   pdf::link::Destination *orig_dest = goto_link->getDest();
   if (orig_dest == nullptr)
-    dest.reset(catalog->findDest(goto_link->getNamedDest()));
+    dest = catalog->findDest(goto_link->getNamedDest());
   else
     dest.reset(orig_dest->copy());
   if (dest.get() != nullptr)
@@ -336,7 +336,7 @@ public:
   }
 
   void drawImage(pdf::gfx::State *state, pdf::Object *object, pdf::Stream *stream, int width, int height,
-    pdf::gfx::ImageColorMap *color_map, bool interpolate, int *mask_colors, bool inline_image)
+    pdf::gfx::ImageColorMap *color_map, bool interpolate, const int *mask_colors, bool inline_image)
   {
     if (is_foreground_color_map(color_map) || config.no_render)
     {
@@ -379,7 +379,7 @@ public:
   bool interpretType3Chars() { return false; }
 
   void drawChar(pdf::gfx::State *state, double x, double y, double dx, double dy, double origin_x, double origin_y,
-    CharCode code, int n_bytes, Unicode *unistr, int length)
+    CharCode code, int n_bytes, const Unicode *unistr, int length)
   {
     double pox, poy, pdx, pdy, px, py, pw, ph;
     x -= origin_x; y -= origin_y;
@@ -459,8 +459,10 @@ public:
     switch (link_action->getKind())
     {
     case actionURI:
-      uri += pdf::get_c_string(dynamic_cast<pdf::link::URI*>(link_action)->getURI());
+    {
+      uri += dynamic_cast<pdf::link::URI*>(link_action)->getURI();
       break;
+    }
     case actionGoTo:
     {
       int page;
@@ -698,9 +700,9 @@ static void pdf_outline_to_djvu_outline(
         pdf::OwnedObject destination;
         std::unique_ptr<pdf::link::Action> link_action;
         if (!pdf::dict_lookup(current, "Dest", &destination)->isNull())
-          link_action.reset(pdf::link::Action::parseDest(&destination));
+          link_action = pdf::link::Action::parseDest(&destination);
         else if (!pdf::dict_lookup(current, "A", &destination)->isNull())
-          link_action.reset(pdf::link::Action::parseAction(&destination));
+          link_action = pdf::link::Action::parseAction(&destination);
         else
           throw NoPageForBookmark();
         if (link_action.get() == nullptr || link_action->getKind() != actionGoTo)
