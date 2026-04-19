$NetBSD: patch-meld_matchers_helpers.py,v 1.2 2026/04/19 10:48:05 wiz Exp $

Another try at closing a file descriptor leak.
https://gitlab.gnome.org/GNOME/meld/-/issues/962

--- meld/matchers/helpers.py.orig	2024-03-24 01:06:00.000000000 +0000
+++ meld/matchers/helpers.py
@@ -1,4 +1,5 @@
 
+import gc
 import logging
 import multiprocessing
 import queue
@@ -76,6 +77,17 @@ class CachedSequenceMatcher:
                 self.thread.terminate()
         self.cache = {}
         self.queued_matches = {}
+        for q in (self.tasks, self.results):
+            if q is not None:
+                q.close()
+                q.join_thread()
+        if self.thread is not None:
+            self.thread.tasks = None
+            self.thread.results = None
+        self.tasks = None
+        self.results = None
+        self.thread = None
+        gc.collect()
 
     def match(self, text1, textn, cb):
         texts = (text1, textn)
