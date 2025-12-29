$NetBSD: patch-beetsplug_lyrics.py,v 1.1 2025/12/29 17:54:58 wiz Exp $

Python 3.14 support from Debian
https://github.com/beetbox/beets/issues/6230

--- beetsplug/lyrics.py.orig	2025-10-14 22:51:25.520185000 +0000
+++ beetsplug/lyrics.py
@@ -745,7 +745,7 @@ class Translator(RequestHandler):
     TRANSLATE_URL = "https://api.cognitive.microsofttranslator.com/translate"
     LINE_PARTS_RE = re.compile(r"^(\[\d\d:\d\d.\d\d\]|) *(.*)$")
     SEPARATOR = " | "
-    remove_translations = partial(re.compile(r" / [^\n]+").sub, "")
+    remove_translations = staticmethod(partial(re.compile(r" / [^\n]+").sub, ""))
 
     _log: Logger
     api_key: str
