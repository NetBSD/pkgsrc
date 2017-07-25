$NetBSD: patch-fastimport_parser.py,v 1.1 2017/07/25 16:10:53 joerg Exp $

--- fastimport/parser.py.orig	2016-04-18 18:09:28.000000000 +0000
+++ fastimport/parser.py
@@ -265,7 +265,7 @@ _WHO_RE = re.compile(br'([^<]*)<(.*)>')
 class ImportParser(LineBasedParser):
 
     def __init__(self, input_stream, verbose=False, output=sys.stdout,
-        user_mapper=None, strict=True):
+        user_mapper=None, strict=True, message_fallback_encoding = None):
         """A Parser of import commands.
 
         :param input_stream: the file-like object to read from
@@ -283,6 +283,7 @@ class ImportParser(LineBasedParser):
         # We auto-detect the date format when a date is first encountered
         self.date_parser = None
         self.features = {}
+        self.message_fallback_encoding = message_fallback_encoding
 
     def warning(self, msg):
         sys.stderr.write("warning line %d: %s\n" % (self.lineno, msg))
@@ -368,6 +369,11 @@ class ImportParser(LineBasedParser):
                 break
         committer = self._get_user_info(b'commit', b'committer')
         message = self._get_data(b'commit', b'message')
+        if self.message_fallback_encoding:
+            try:
+                message.decode('UTF-8')
+            except:
+                message = message.decode(self.message_fallback_encoding).encode('UTF-8')
         from_ = self._get_from()
         merges = []
         while True:
@@ -432,6 +438,11 @@ class ImportParser(LineBasedParser):
         tagger = self._get_user_info(b'tag', b'tagger',
                 accept_just_who=True)
         message = self._get_data(b'tag', b'message')
+        if self.message_fallback_encoding:
+            try:
+                message.decode('UTF-8')
+            except:
+                message = message.decode(self.message_fallback_encoding).encode('UTF-8')
         return commands.TagCommand(name, from_, tagger, message)
 
     def _get_mark_if_any(self):
