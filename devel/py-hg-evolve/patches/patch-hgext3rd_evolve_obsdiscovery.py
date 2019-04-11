$NetBSD: patch-hgext3rd_evolve_obsdiscovery.py,v 1.1 2019/04/11 13:27:55 joerg Exp $

Fix interaction with share extension.

--- hgext3rd/evolve/obsdiscovery.py.orig	2019-01-23 00:11:32.000000000 +0000
+++ hgext3rd/evolve/obsdiscovery.py
@@ -412,12 +412,12 @@ class _obshashcache(obscache.dualsourcec
     _schemaversion = 3
 
     _cachename = 'evo-ext-obshashrange' # used for error message
-    _filename = 'cache/evoext_obshashrange_v2.sqlite'
+    _filename = 'evoext_obshashrange_v2.sqlite'
 
     def __init__(self, repo):
         super(_obshashcache, self).__init__()
         self._vfs = repo.vfs
-        self._path = repo.vfs.join(self._filename)
+        self._path = repo.cachevfs.join(self._filename)
         self._new = set()
         self._valid = True
         self._repo = weakref.ref(repo.unfiltered())
