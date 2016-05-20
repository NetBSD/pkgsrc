$NetBSD: patch-tests_test-subrepo-git.t,v 1.1 2016/05/20 17:52:26 wiz Exp $

# HG changeset patch
# User Kevin Bullock <kbullock+mercurial@ringworld.org>
# Date 1462542084 18000
# Node ID 3879d02cd1cc5b86ab23a4280115bcf37375dd61
# Parent  8d5584d8345be23f98f702a421ce31b71882b4e6
subrepo: use unset instead of env -u to fix test on BSDs (issue5229)

--- tests/test-subrepo-git.t.orig	2016-05-01 19:36:10.000000000 +0000
+++ tests/test-subrepo-git.t
@@ -1145,7 +1145,8 @@ test for Git CVE-2016-3068
   $ hg add .hgsub
   $ hg commit -m "add subrepo"
   $ cd ..
-  $ env -u GIT_ALLOW_PROTOCOL hg clone malicious-subrepository malicious-subrepository-protected
+  $ unset GIT_ALLOW_PROTOCOL
+  $ hg clone malicious-subrepository malicious-subrepository-protected
   Cloning into '$TESTTMP/tc/malicious-subrepository-protected/s'... (glob)
   fatal: transport 'ext' not allowed
   updating to branch default
