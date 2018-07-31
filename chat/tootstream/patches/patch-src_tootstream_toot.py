$NetBSD: patch-src_tootstream_toot.py,v 1.1 2018/07/31 16:15:33 nia Exp $

'async' is a reserved keyword in Python 3.7.

--- src/tootstream/toot.py.orig	2018-05-31 00:06:11.000000000 +0000
+++ src/tootstream/toot.py
@@ -1279,11 +1279,11 @@ def stream(mastodon, rest):
 
     try:
         if rest == "home" or rest == "":
-            handle = mastodon.stream_user(toot_listener, async=True)
+            handle = mastodon.stream_user(toot_listener, run_async=True)
         elif rest == "fed" or rest == "public":
-            handle = mastodon.stream_public(toot_listener, async=True)
+            handle = mastodon.stream_public(toot_listener, run_async=True)
         elif rest == "local":
-            handle = mastodon.stream_local(toot_listener, async=True)
+            handle = mastodon.stream_local(toot_listener, run_async=True)
         elif rest.startswith('list'):
             # Remove list from the rest string
             items = rest.split('list ')
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
