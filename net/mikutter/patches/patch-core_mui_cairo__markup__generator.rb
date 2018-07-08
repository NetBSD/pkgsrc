$NetBSD: patch-core_mui_cairo__markup__generator.rb,v 1.1 2018/07/08 06:08:09 tsutsui Exp $

- pull upstream fix
  https://dev.mikutter.hachune.net/issues/1242

--- core/mui/cairo_markup_generator.rb.orig	2018-06-10 15:38:30.000000000 +0000
+++ core/mui/cairo_markup_generator.rb
@@ -31,7 +31,7 @@ module Gdk::MarkupGenerator
   # ==== Return
   # Pango::AttrList 本文に適用する装飾
   def description_attr_list(attr_list=Pango::AttrList.new, emoji_height: 24)
-    Plugin[:gtk].score_of(message).inject(0){|start_index, note|
+    score.inject(0){|start_index, note|
       end_index = start_index + note.description.bytesize
       if UserConfig[:miraclepainter_expand_custom_emoji] && note.respond_to?(:inline_photo)
         end_index += -note.description.bytesize + 1
