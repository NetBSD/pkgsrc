$NetBSD: patch-tests_test-evolve-content-divergent-case-A2.t,v 1.1 2025/09/23 00:27:13 joerg Exp $

Fix GNUism.

--- tests/test-evolve-content-divergent-case-A2.t.orig	2025-07-25 16:21:02.000000000 +0000
+++ tests/test-evolve-content-divergent-case-A2.t
@@ -55,7 +55,7 @@ initial
   $ cd local
   $ mkcommit A0
   $ hg push -q
-  $ sed -i '1ifoo' A0
+  $ sed -i '1s/^/foo\n/' A0
   $ hg amend -m "A1"
   $ hg log -G --hidden
   @  2:e1f7c24563ba (draft): A1
