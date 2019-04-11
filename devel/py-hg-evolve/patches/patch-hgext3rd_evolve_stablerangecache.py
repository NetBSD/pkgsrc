$NetBSD: patch-hgext3rd_evolve_stablerangecache.py,v 1.1 2019/04/11 13:27:55 joerg Exp $

Fix interaction with share extension.

--- hgext3rd/evolve/stablerangecache.py.orig	2019-01-23 00:11:32.000000000 +0000
+++ hgext3rd/evolve/stablerangecache.py
@@ -176,7 +176,7 @@ class stablerangesqlbase(stablerange.sta
     def __init__(self, repo, **kwargs):
         super(stablerangesqlbase, self).__init__(**kwargs)
         self._vfs = repo.vfs
-        self._path = repo.vfs.join(self._cachefile)
+        self._path = repo.cachevfs.join(self._cachefile)
         self._cl = repo.unfiltered().changelog # (okay to keep an old one)
         self._ondisktiprev = None
         self._ondisktipnode = None
@@ -390,13 +390,13 @@ class stablerangesql(stablerangesqlbase,
 class mergepointsql(stablerangesql, stablerange.stablerange_mergepoint):
 
     _schemaversion = 3
-    _cachefile = 'cache/evoext_stablerange_v2.sqlite'
+    _cachefile = 'evoext_stablerange_v2.sqlite'
     _cachename = 'evo-ext-stablerange-mergepoint'
 
 class sqlstablerange(stablerangesqlbase, stablerange.stablerange):
 
     _schemaversion = 1
-    _cachefile = 'cache/evoext_stablerange_v1.sqlite'
+    _cachefile = 'evoext_stablerange_v1.sqlite'
 
     def warmup(self, repo, upto=None):
         self._con # make sure the data base is loaded
