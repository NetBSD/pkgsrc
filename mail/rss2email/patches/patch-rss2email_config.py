$NetBSD: patch-rss2email_config.py,v 1.1 2017/05/22 17:51:12 leot Exp $

Properly pass the configuration options to html2text

--- rss2email/config.py.orig	2014-09-01 23:21:01.000000000 +0000
+++ rss2email/config.py
@@ -51,11 +51,11 @@ class Config (_configparser.ConfigParser
         """
         if section not in self:
             section = 'DEFAULT'
-        _html2text.UNICODE_SNOB = self.getboolean(
+        _html2text.config.UNICODE_SNOB = self.getboolean(
             section, 'unicode-snob')
-        _html2text.LINKS_EACH_PARAGRAPH = self.getboolean(
+        _html2text.config.LINKS_EACH_PARAGRAPH = self.getboolean(
             section, 'links-after-each-paragraph')
-        _html2text.BODY_WIDTH = self.getint(section, 'body-width')
+        _html2text.config.BODY_WIDTH = self.getint(section, 'body-width')
 
 
 CONFIG = Config()
