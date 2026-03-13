$NetBSD: patch-core_mui_cairo__sub__parts__message__base.rb,v 1.1 2026/03/13 17:09:50 tsutsui Exp $

- pull fix for upstream ticket #1290
  https://dev.mikutter.hachune.net/issues/1290

--- core/mui/cairo_sub_parts_message_base.rb.orig	2025-02-08 12:21:47.000000000 +0000
+++ core/mui/cairo_sub_parts_message_base.rb
@@ -367,7 +367,8 @@ class Gdk::SubPartsMessageBase < Gdk::Su
       layout.width = (width - icon_width - margin*3 - edge*2) * Pango::SCALE
       layout.attributes = description_attr_list(
         message,
-        emoji_height: layout.context.font_description.forecast_font_size
+        emoji_height: layout.context.font_description.forecast_font_size,
+        pango_context: layout.context
       )
       layout.wrap = Pango::WrapMode::CHAR
       layout.text = plain_description(message)
@@ -489,12 +490,19 @@ class Gdk::SubPartsMessageBase < Gdk::Su
   # 表示する際に本文に適用すべき装飾オブジェクトを作成する
   # ==== Return
   # Pango::AttrList 本文に適用する装飾
-  def description_attr_list(message, attr_list: Pango::AttrList.new, emoji_height: 24)
+  def description_attr_list(message, attr_list: Pango::AttrList.new, emoji_height: 24, pango_context: nil)
+    descent = 0
+    if pango_context
+      metrics = pango_context.get_metrics(pango_context.font_description, pango_context.language)
+      descent = metrics.descent
+    end
+    height = emoji_height * Pango::SCALE
+    y = -height + descent
     score(message).inject(0){|start_index, note|
       end_index = start_index + note.description.bytesize
       if UserConfig[:miraclepainter_expand_custom_emoji] && note.respond_to?(:inline_photo)
         end_index += -note.description.bytesize + 1
-        rect = Pango::Rectangle.new(0, 0, emoji_height * Pango::SCALE, emoji_height * Pango::SCALE)
+        rect = Pango::Rectangle.new(0, y, height, height)
         shape = Pango::AttrShape.new(rect, rect, note.inline_photo)
         shape.start_index = start_index
         shape.end_index = end_index
