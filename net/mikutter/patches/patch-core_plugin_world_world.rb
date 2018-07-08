$NetBSD: patch-core_plugin_world_world.rb,v 1.1 2018/07/08 06:08:09 tsutsui Exp $

- pull upstream fix
  https://dev.mikutter.hachune.net/issues/1231

--- core/plugin/world/world.rb.orig	2018-06-10 15:38:30.000000000 +0000
+++ core/plugin/world/world.rb
@@ -10,6 +10,7 @@ miquire :lib, 'diva_hacks'
 Plugin.create(:world) do
 
   world_struct = Struct.new(:slug, :name, :proc)
+  @world_slug_dict = {}         # world_slug(Symbol) => World URI(Diva::URI)
 
   defdsl :world_setting do |world_slug, world_name, &proc|
     filter_world_setting_list do |settings|
@@ -103,6 +104,18 @@ Plugin.create(:world) do
           nil
         end
       end
-    }.compact.freeze
+    }.compact.freeze.tap(&method(:check_world_uri))
+  end
+
+  def check_world_uri(new_worlds)
+    new_worlds.each do |w|
+      if @world_slug_dict.key?(w.slug)
+        if @world_slug_dict[w.slug] != w.uri
+          warn "The URI of World `#{w.slug}' is not defined. You must define a consistent URI for World Model. see: https://dev.mikutter.hachune.net/issues/1231"
+        end
+      else
+        @world_slug_dict[w.slug] = w.uri
+      end
+    end
   end
 end
