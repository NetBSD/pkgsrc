$NetBSD: patch-rss2email_feed.py,v 1.1 2013/07/02 01:13:30 schmonz Exp $

Upstream 4aa7f1d: "Fixed syntactical error when generating HTML mails"

--- rss2email/feed.py.orig	2013-06-05 22:13:14.000000000 +0000
+++ rss2email/feed.py
@@ -709,7 +709,7 @@ class Feed (object):
             lines.extend([
                     '</head>',
                     '<body>',
-                    '<div id="entry>',
+                    '<div id="entry">',
                     '<h1 class="header"><a href="{}">{}</a></h1>'.format(
                         link, subject),
                     '<div id="body">',
