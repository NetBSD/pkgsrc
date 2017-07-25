$NetBSD: patch-mercurial_localrepo.py,v 1.1 2017/07/25 16:09:40 joerg Exp $

https://www.mercurial-scm.org/repo/hg/rev/7e89b

--- mercurial/localrepo.py.orig	2017-06-04 13:16:29.000000000 +0000
+++ mercurial/localrepo.py
@@ -382,6 +382,9 @@ class localrepository(object):
         # - bookmark changes
         self.filteredrevcache = {}
 
+        # Cache of types representing filtered repos.
+        self._filteredrepotypes = weakref.WeakKeyDictionary()
+
         # generic mapping between names and nodes
         self.names = namespaces.namespaces()
 
@@ -489,11 +492,21 @@ class localrepository(object):
 
     def filtered(self, name):
         """Return a filtered version of a repository"""
-        # build a new class with the mixin and the current class
-        # (possibly subclass of the repo)
-        class filteredrepo(repoview.repoview, self.unfiltered().__class__):
-            pass
-        return filteredrepo(self, name)
+        # Python <3.4 easily leaks types via __mro__. See
+        # https://bugs.python.org/issue17950. We cache dynamically
+        # created types so this method doesn't leak on every
+        # invocation.
+
+        key = self.unfiltered().__class__
+        if key not in self._filteredrepotypes:
+            # Build a new type with the repoview mixin and the base
+            # class of this repo. Give it a name containing the
+            # filter name to aid debugging.
+            bases = (repoview.repoview, key)
+            cls = type('%sfilteredrepo' % name, bases, {})
+            self._filteredrepotypes[key] = cls
+
+        return self._filteredrepotypes[key](self, name)
 
     @repofilecache('bookmarks', 'bookmarks.current')
     def _bookmarks(self):
