$NetBSD: patch-mastodon_Mastodon.py,v 1.4 2018/10/01 16:31:11 nia Exp $

Make this work with Pleroma, which grants all scopes regardless of
what gets requested.

--- mastodon/Mastodon.py.orig	2018-07-30 21:34:05.000000000 +0000
+++ mastodon/Mastodon.py
@@ -428,10 +428,6 @@ class Mastodon:
             if scope_set in received_scopes:
                 received_scopes += self.__SCOPE_SETS[scope_set]
         
-        if not set(scopes) <= set(received_scopes):
-            raise MastodonAPIError(
-                'Granted scopes "' + " ".join(received_scopes) + '" do not contain all of the requested scopes "' + " ".join(scopes) + '".')
-
         if to_file is not None:
             with open(to_file, 'w') as token_file:
                 token_file.write(response['access_token'] + '\n')
