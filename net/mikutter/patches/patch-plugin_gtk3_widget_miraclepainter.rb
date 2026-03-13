$NetBSD: patch-plugin_gtk3_widget_miraclepainter.rb,v 1.1 2026/03/13 17:09:50 tsutsui Exp $

- pull fix for upstream ticket #1290
  https://dev.mikutter.hachune.net/issues/1290

--- plugin/gtk3/widget/miraclepainter.rb.orig	2025-02-08 12:21:47.000000000 +0000
+++ plugin/gtk3/widget/miraclepainter.rb
@@ -467,7 +467,7 @@ class Plugin::Gtk3::MiraclePainter < Gtk
     layout.text = plain_description
     layout.width = main_text_rect.width * Pango::SCALE
     layout.attributes = textselector_attr_list(
-      description_attr_list(emoji_height: layout.context.font_description.forecast_font_size)
+      description_attr_list(emoji_height: layout.context.font_description.forecast_font_size, pango_context: layout.context)
     )
     layout.wrap = Pango::WrapMode::CHAR
     if context
