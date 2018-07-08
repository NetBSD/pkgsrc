$NetBSD: patch-core_plugin_current__world_current__world.rb,v 1.1 2018/07/08 06:08:09 tsutsui Exp $

- pull upstream fix
  https://dev.mikutter.hachune.net/issues/1231

--- core/plugin/current_world/current_world.rb.orig	2018-06-10 15:38:30.000000000 +0000
+++ core/plugin/current_world/current_world.rb
@@ -1,5 +1,7 @@
 # -*- coding: utf-8 -*-
 
+require_relative 'error'
+
 Plugin.create(:current_world) do
   # 現在選択されているアカウントに対応するModelを返すフィルタ。
   filter_world_current do |result|
@@ -17,8 +19,13 @@ Plugin.create(:current_world) do
         self.current_world = new
         Plugin.call(:primary_service_changed, current_world)
       end
-    rescue RuntimeError => err
-      error err
+    rescue Plugin::CurrentWorld::WorldNotfoundError
+      activity :system, _('アカウントを存在しないアカウント(%{uri})に切り替えようとしました') % {uri: new&.uri || 'nil'},
+               description: _('アカウントを切り替えようとしましたが、切り替えようとしたアカウントは存在しませんでした。') + "\n\n" +
+               _("切り替え先のアカウント:\n%{uri}") % {uri: new&.uri || 'nil'} + "\n\n" +
+               _('現在存在するアカウント:') + "\n" +
+               Enumerator.new{|y| Plugin.filtering(:worlds, y) }.map{|w| "#{w.slug} (#{w.uri})" }.to_a.join("\n") + "\n\n" +
+               _('%{world_class}#uri を定義することでこのエラーを回避できます。詳しくは %{see} を参照してください') % {world_class: new.class, see: 'https://dev.mikutter.hachune.net/issues/1231'}
     end
   end
 
@@ -39,7 +46,7 @@ Plugin.create(:current_world) do
   # ==== Raise
   # [Plugin::World::InvalidWorldError] _worlds_ にないアカウントが渡された場合
   def current_world=(new)
-    raise RuntimeError unless Enumerator.new{|y| Plugin.filtering(:worlds, y) }.include?(new)
+    raise Plugin::CurrentWorld::WorldNotfoundError unless Enumerator.new{|y| Plugin.filtering(:worlds, y) }.include?(new)
     @current = new
   end
 
