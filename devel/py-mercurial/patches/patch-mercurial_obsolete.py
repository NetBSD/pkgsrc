$NetBSD: patch-mercurial_obsolete.py,v 1.1 2024/06/20 23:56:45 joerg Exp $

Upstream f28c52a9f7b4

--- mercurial/obsolete.py.orig	2024-03-29 20:37:05.000000000 +0000
+++ mercurial/obsolete.py
@@ -771,10 +771,11 @@ class obsstore:
             _addchildren(self.children, markers)
         _checkinvalidmarkers(self.repo, markers)
 
-    def relevantmarkers(self, nodes):
-        """return a set of all obsolescence markers relevant to a set of nodes.
+    def relevantmarkers(self, nodes=None, revs=None):
+        """return a set of all obsolescence markers relevant to a set of
+        nodes or revisions.
 
-        "relevant" to a set of nodes mean:
+        "relevant" to a set of nodes or revisions mean:
 
         - marker that use this changeset as successor
         - prune marker of direct children on this changeset
@@ -782,10 +783,24 @@ class obsstore:
           markers
 
         It is a set so you cannot rely on order."""
+        if nodes is None:
+            nodes = set()
+        if revs is None:
+            revs = set()
 
-        pendingnodes = set(nodes)
+        get_rev = self.repo.unfiltered().changelog.index.get_rev
+        pendingnodes = set()
+        for marker in self._all:
+            for node in (marker[0],) + marker[1] + (marker[5] or ()):
+                if node in nodes:
+                    pendingnodes.add(node)
+                elif revs:
+                    rev = get_rev(node)
+                    if rev is not None and rev in revs:
+                        pendingnodes.add(node)
         seenmarkers = set()
-        seennodes = set(pendingnodes)
+        seenmarkers = set()
+        seennodes = set()
         precursorsmarkers = self.predecessors
         succsmarkers = self.successors
         children = self.children
