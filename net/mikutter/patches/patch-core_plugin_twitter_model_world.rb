$NetBSD: patch-core_plugin_twitter_model_world.rb,v 1.1 2018/07/08 06:08:09 tsutsui Exp $

- pull upstream fix
  https://dev.mikutter.hachune.net/issues/1231

--- core/plugin/twitter/model/world.rb.orig	2018-06-10 15:38:30.000000000 +0000
+++ core/plugin/twitter/model/world.rb
@@ -53,6 +53,10 @@ module Plugin::Twitter
                          profile_image_url: user_obj.icon.perma_link.to_s})
     end
 
+    def path
+      "/#{slug}"
+    end
+
     # サービスにクエリ _kind_ を投げる。
     # レスポンスを受け取るまでブロッキングする。
     # レスポンスを返す。失敗した場合は、apifailイベントを発生させてnilを返す。
