$NetBSD: patch-meld_matchers_helpers.py,v 1.1 2026/04/16 06:30:38 wiz Exp $

Another try at closing a file descriptor leak.

--- meld/matchers/helpers.py.orig	2026-04-12 07:49:00.516252865 +0000
+++ meld/matchers/helpers.py
@@ -76,6 +76,11 @@ class CachedSequenceMatcher:
                 self.thread.terminate()
         self.cache = {}
         self.queued_matches = {}
+        for q in (self.tasks, self.results):
+            try:
+                q.close()
+            except:
+                pass
 
     def match(self, text1, textn, cb):
         texts = (text1, textn)
