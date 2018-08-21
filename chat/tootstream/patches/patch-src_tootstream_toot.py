$NetBSD: patch-src_tootstream_toot.py,v 1.2 2018/08/21 17:34:48 nia Exp $

'async' is a reserved keyword in Python 3.7.

--- src/tootstream/toot.py.orig	2018-08-09 00:55:08.000000000 +0000
+++ src/tootstream/toot.py
@@ -1295,10 +1295,10 @@ def stream(mastodon, rest):
                 cprint("List {} is not found".format(items[-1]), fg('red'))
                 return
 
-            handle = mastodon.stream_list(item, toot_listener, async=True)
+            handle = mastodon.stream_list(item, toot_listener, run_async=True)
         elif rest.startswith('#'):
             tag = rest[1:]
-            handle = mastodon.stream_hashtag(tag, toot_listener, async=True)
+            handle = mastodon.stream_hashtag(tag, toot_listener, run_async=True)
         else:
             handle = None
             print("Only 'home', 'fed', 'local', 'list', and '#hashtag' streams are supported.")
