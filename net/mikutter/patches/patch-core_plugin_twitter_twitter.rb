$NetBSD: patch-core_plugin_twitter_twitter.rb,v 1.1 2019/05/25 12:14:04 tsutsui Exp $

- pull patches to insert newline to each attached image URL (redmine #1323)

--- core/plugin/twitter/twitter.rb.orig	2019-04-29 06:54:31.000000000 +0000
+++ core/plugin/twitter/twitter.rb
@@ -435,7 +435,7 @@ Plugin.create(:twitter) do
   def extended_entity_media(tweet)
     extended_entities = (tweet[:extended_entities][:media] rescue nil)
     if extended_entities
-      space = text_note(description: ' ')
+      newline = text_note(description: "\n")
       result = extended_entities.map{ |media|
         case media[:type]
         when 'photo'
@@ -468,8 +468,7 @@ Plugin.create(:twitter) do
             description: "#{media[:display_url]} (GIF)",
             uri: variant[:url])
         end
-      }.flat_map{|media| [media, space] }
-      result.pop
+      }.flat_map{|media| [newline, media] }
       result
     else
       []
