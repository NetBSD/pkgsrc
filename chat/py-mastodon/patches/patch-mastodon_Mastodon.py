$NetBSD: patch-mastodon_Mastodon.py,v 1.2 2018/07/31 21:14:33 nia Exp $

'async' is a reserved keyword in Python 3.7.

--- mastodon/Mastodon.py.orig	2018-01-29 14:20:16.000000000 +0000
+++ mastodon/Mastodon.py
@@ -1381,45 +1381,45 @@ class Mastodon:
     # Streaming
     ###
     @api_version("1.1.0", "1.4.2")    
-    def stream_user(self, listener, async=False):
+    def stream_user(self, listener, run_async=False):
         """
         Streams events that are relevant to the authorized user, i.e. home
         timeline and notifications.
         """
-        return self.__stream('/api/v1/streaming/user', listener, async=async)
+        return self.__stream('/api/v1/streaming/user', listener, run_async=run_async)
 
     @api_version("1.1.0", "1.4.2")
-    def stream_public(self, listener, async=False):
+    def stream_public(self, listener, run_async=False):
         """
         Streams public events.
         """
-        return self.__stream('/api/v1/streaming/public', listener, async=async)
+        return self.__stream('/api/v1/streaming/public', listener, run_async=run_async)
 
     @api_version("1.1.0", "1.4.2")
-    def stream_local(self, listener, async=False):
+    def stream_local(self, listener, run_async=False):
         """
         Streams local public events.
         """
-        return self.__stream('/api/v1/streaming/public/local', listener, async=async)
+        return self.__stream('/api/v1/streaming/public/local', listener, run_async=run_async)
 
     @api_version("1.1.0", "1.4.2")
-    def stream_hashtag(self, tag, listener, async=False):
+    def stream_hashtag(self, tag, listener, run_async=False):
         """
         Stream for all public statuses for the hashtag 'tag' seen by the connected
         instance.
         """
         if tag.startswith("#"):
             raise MastodonIllegalArgumentError("Tag parameter should omit leading #")
-        return self.__stream("/api/v1/streaming/hashtag?tag={}".format(tag), listener, async=async)
+        return self.__stream("/api/v1/streaming/hashtag?tag={}".format(tag), listener, run_async=run_async)
 
     @api_version("2.1.0", "2.1.0")
-    def stream_list(self, id, listener, async=False):
+    def stream_list(self, id, listener, run_async=False):
         """
         Stream events for the current user, restricted to accounts on the given
         list. 
         """
         id =  self.__unpack_id(id)
-        return self.__stream("/api/v1/streaming/list?list={}".format(id), listener, async=async)
+        return self.__stream("/api/v1/streaming/list?list={}".format(id), listener, run_async=run_async)
     
     ###
     # Internal helpers, dragons probably
@@ -1661,7 +1661,7 @@ class Mastodon:
 
         return response
 
-    def __stream(self, endpoint, listener, params={}, async=False):
+    def __stream(self, endpoint, listener, params={}, run_async=False):
         """
         Internal streaming API helper.
 
@@ -1720,7 +1720,7 @@ class Mastodon:
 
         handle = __stream_handle(connection)
 
-        if async:
+        if run_async:
             t = threading.Thread(args=(), daemon = True, target=handle._threadproc)
             t.start()
             return handle
