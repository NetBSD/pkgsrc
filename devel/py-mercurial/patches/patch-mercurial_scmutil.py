$NetBSD: patch-mercurial_scmutil.py,v 1.1 2018/09/03 12:46:59 joerg Exp $

Upstream: d750a6c9248d
Avoid quadratic behavior for pull/clone

--- mercurial/scmutil.py.orig	2018-08-01 14:20:18.000000000 +0000
+++ mercurial/scmutil.py
@@ -1565,7 +1565,10 @@ def registersummarycallback(repo, otr, t
             """Report statistics of phase changes for changesets pre-existing
             pull/unbundle.
             """
-            newrevs = tr.changes.get('revs', xrange(0, 0))
+            # TODO set() is only appropriate for 4.7 since revs post
+            # 45e05d39d9ce is a pycompat.membershiprange, which has O(n)
+            # membership testing.
+            newrevs = set(tr.changes.get('revs', xrange(0, 0)))
             phasetracking = tr.changes.get('phases', {})
             if not phasetracking:
                 return
