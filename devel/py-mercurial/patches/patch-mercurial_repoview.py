$NetBSD: patch-mercurial_repoview.py,v 1.1 2016/03/02 19:31:13 wiz Exp $

changeset:   34663:332926212ef8
user:        FUJIWARA Katsunori <foozy@lares.dti.ne.jp>
date:        Wed Feb 24 06:10:46 2016 +0900
files:       mercurial/repoview.py tests/test-commandserver.t
description:
repoview: discard filtered changelog if index isn't shared with unfiltered

--- mercurial/repoview.py.orig	2016-03-02 00:03:43.000000000 +0000
+++ mercurial/repoview.py
@@ -315,7 +315,10 @@ class repoview(object):
         revs = filterrevs(unfi, self.filtername)
         cl = self._clcache
         newkey = (unfilen, unfinode, hash(revs), unfichangelog._delayed)
-        if cl is not None and newkey != self._clcachekey:
+        # if cl.index is not unfiindex, unfi.changelog would be
+        # recreated, and our clcache refers to garbage object
+        if (cl is not None and
+            (cl.index is not unfiindex or newkey != self._clcachekey)):
             cl = None
         # could have been made None by the previous if
         if cl is None:
