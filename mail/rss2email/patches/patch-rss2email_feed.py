$NetBSD: patch-rss2email_feed.py,v 1.3 2019/08/28 19:44:48 schmonz Exp $

html2text no longer provides unescape(). Python 3.4's html module does.
<https://github.com/rss2email/rss2email/commit/81824e25723dcd2936f25f64ebc16f2e8ec9f310>

--- rss2email/feed.py.orig	2014-09-01 23:21:01.000000000 +0000
+++ rss2email/feed.py
@@ -48,6 +48,7 @@ import xml.sax.saxutils as _saxutils
 
 import feedparser as _feedparser
 import html2text as _html2text
+import html as _html
 
 from . import __url__
 from . import __version__
@@ -595,7 +596,7 @@ class Feed (object):
         if 'name' in feed.get('publisher_detail', []):
             data['publisher'] = feed.publisher_detail.name
         name = self.name_format.format(**data)
-        return _html2text.unescape(name)
+        return _html.unescape(name)
 
     def _validate_email(self, email, default=None):
         """Do a basic quality check on email address
