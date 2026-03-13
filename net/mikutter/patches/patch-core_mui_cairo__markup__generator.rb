$NetBSD: patch-core_mui_cairo__markup__generator.rb,v 1.3 2026/03/13 17:09:50 tsutsui Exp $

- pull fix for upstream ticket #1290
  https://dev.mikutter.hachune.net/issues/1290

--- core/mui/cairo_markup_generator.rb.orig	2025-02-08 12:21:47.000000000 +0000
+++ core/mui/cairo_markup_generator.rb
@@ -33,12 +33,19 @@ module Gdk::MarkupGenerator
   # 表示する際に本文に適用すべき装飾オブジェクトを作成する
   # ==== Return
   # Pango::AttrList 本文に適用する装飾
-  def description_attr_list(attr_list=Pango::AttrList.new, emoji_height: 24)
+  def description_attr_list(attr_list=Pango::AttrList.new, emoji_height: 24, pango_context: nil)
+    descent = 0
+    if pango_context
+      metrics = pango_context.get_metrics(pango_context.font_description, pango_context.language)
+      descent = metrics.descent
+    end
+    height = emoji_height * Pango::SCALE
+    y = -height + descent
     score.inject(0){|start_index, note|
       end_index = start_index + note.description.bytesize
       if UserConfig[:miraclepainter_expand_custom_emoji] && note.respond_to?(:inline_photo)
         end_index += -note.description.bytesize + 1
-        rect = Pango::Rectangle.new(0, 0, emoji_height * Pango::SCALE, emoji_height * Pango::SCALE)
+        rect = Pango::Rectangle.new(0, y, height, height)
         shape = Pango::AttrShape.new(rect, rect, note.inline_photo)
         shape.start_index = start_index
         shape.end_index = end_index
