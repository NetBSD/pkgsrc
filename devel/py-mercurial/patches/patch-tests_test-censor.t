$NetBSD: patch-tests_test-censor.t,v 1.1 2021/10/13 12:35:29 wiz Exp $

Fix test.
https://bz.mercurial-scm.org/show_bug.cgi?id=6585

--- tests/test-censor.t.orig	2021-10-05 15:47:21.000000000 +0000
+++ tests/test-censor.t
@@ -552,14 +552,14 @@ Make sure the last revision is a delta a
 Censor the file
 
   $ hg cat -r $B1 target | wc -l
-  50002 (re)
+   *50002 (re)
   $ hg censor -r $B1 target
   $ hg cat -r $B1 target | wc -l
-  0 (re)
+   *0 (re)
 
 Check the children is fine
 
   $ hg cat -r $B2 target | wc -l
-  50003 (re)
+   *50003 (re)
 
 #endif
