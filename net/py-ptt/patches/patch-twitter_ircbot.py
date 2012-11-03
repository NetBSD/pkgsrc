$NetBSD: patch-twitter_ircbot.py,v 1.1 2012/11/03 14:29:25 imil Exp $

Upstream imports "irclib" but that library has changed to "irc"

--- twitter/ircbot.py.orig	2012-05-10 21:20:42.000000000 +0000
+++ twitter/ircbot.py
@@ -81,7 +81,7 @@ def get_prefix(prefix_typ=None):
 
 
 try:
-    import irclib
+    import irc
 except ImportError:
     raise ImportError(
         "This module requires python irclib available from "
