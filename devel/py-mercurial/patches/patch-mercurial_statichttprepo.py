$NetBSD: patch-mercurial_statichttprepo.py,v 1.1 2017/07/25 16:09:40 joerg Exp $

https://www.mercurial-scm.org/repo/hg/rev/7e89b

--- mercurial/statichttprepo.py.orig	2017-06-04 13:16:29.000000000 +0000
+++ mercurial/statichttprepo.py
@@ -164,6 +164,8 @@ class statichttprepository(localrepo.loc
         self.encodepats = None
         self.decodepats = None
         self._transref = None
+        # Cache of types representing filtered repos.
+        self._filteredrepotypes = {}
 
     def _restrictcapabilities(self, caps):
         caps = super(statichttprepository, self)._restrictcapabilities(caps)
