$NetBSD: patch-plugin_mastodon_mastodon.rb,v 1.1 2023/07/23 17:20:12 tsutsui Exp $

- pull upstream fix https://dev.mikutter.hachune.net/issues/1590

--- plugin/mastodon/mastodon.rb.orig	2022-01-29 23:56:32.000000000 +0000
+++ plugin/mastodon/mastodon.rb
@@ -232,7 +232,7 @@ Plugin.create(:mastodon) do
                       world.rest.public_local.datasource_slug,
                       world.sse.public_local.datasource_slug,
                     ],
-                    icon: 'https://%{domain}/apple-touch-icon.png' % slug_param,
+                    icon: 'https://%{domain}/favicon.ico' % slug_param,
                   })
     end
   end
