$NetBSD: patch-tests_test-merge-tools.t,v 1.1 2015/04/04 11:20:35 wiz Exp $

# HG changeset patch
# User Martin von Zweigbergk <martinvonz@google.com>
# Date 1423613835 28800
#      Tue Feb 10 16:17:15 2015 -0800
# Node ID 9d0b6ef92eb212bf4945822139dac996c4e1322c
# Parent  a450e0a2ba0ae28f84125cc6d9ada7790e2a2816
test-merge-tools: fix flaky test by avoiding debugsetparents

debugsetparents is a debug command and does not provide the same
guarantees as non-debug commands do. In particular, when the user sets
a different parent, any clean files will remain clean in the dirstate
even though the new parent might have a different version of the file
(so it should appear modified compared to the new parent). Let's
instead achieve the same effect by updating to the new parent and
reverting the contents back to what they were.

This fix can be tested by passing '--config
debug.dirstate.delaywrite=2' to the 'hg update' command in the
beforemerge().

--- tests/test-merge-tools.t.orig	2015-04-01 18:27:41.000000000 +0000
+++ tests/test-merge-tools.t
@@ -603,7 +603,8 @@ update is a merge ...
   true.priority=1
   true.executable=cat
   # hg update -C 1
-  $ hg debugsetparent 0
+  $ hg update -q 0
+  $ hg revert -q -r 1 .
   $ hg update -r 2
   merging f
   revision 1
@@ -628,7 +629,8 @@ update should also have --tool
   true.priority=1
   true.executable=cat
   # hg update -C 1
-  $ hg debugsetparent 0
+  $ hg update -q 0
+  $ hg revert -q -r 1 .
   $ hg update -r 2 --tool false
   merging f
   merging f failed!
