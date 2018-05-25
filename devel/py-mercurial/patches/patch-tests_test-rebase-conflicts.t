$NetBSD: patch-tests_test-rebase-conflicts.t,v 1.1 2018/05/25 13:04:56 joerg Exp $

Merge 326b174c6a47 from upstream:
bundle2: mark the bundle2 part as advisory (issue5872)

--- tests/test-rebase-conflicts.t.orig	2018-05-05 23:02:58.000000000 +0000
+++ tests/test-rebase-conflicts.t
@@ -298,7 +298,7 @@ Check that the right ancestors is used w
   2f2496ddf49d69b5ef23ad8cf9fb2e0e4faf0ac2
   bundle2-output-bundle: "HG20", (1 params) 3 parts total
   bundle2-output-part: "changegroup" (params: 1 mandatory 1 advisory) streamed payload
-  bundle2-output-part: "cache:rev-branch-cache" streamed payload
+  bundle2-output-part: "cache:rev-branch-cache" (advisory) streamed payload
   bundle2-output-part: "phase-heads" 24 bytes payload
   saved backup bundle to $TESTTMP/issue4041/.hg/strip-backup/e31216eec445-15f7a814-rebase.hg
   3 changesets found
@@ -308,7 +308,7 @@ Check that the right ancestors is used w
   2a7f09cac94c7f4b73ebd5cd1a62d3b2e8e336bf
   bundle2-output-bundle: "HG20", 3 parts total
   bundle2-output-part: "changegroup" (params: 1 mandatory 1 advisory) streamed payload
-  bundle2-output-part: "cache:rev-branch-cache" streamed payload
+  bundle2-output-part: "cache:rev-branch-cache" (advisory) streamed payload
   bundle2-output-part: "phase-heads" 24 bytes payload
   adding branch
   bundle2-input-bundle: with-transaction
@@ -322,7 +322,7 @@ Check that the right ancestors is used w
   adding f1.txt revisions
   added 2 changesets with 2 changes to 1 files
   bundle2-input-part: total payload size 1686
-  bundle2-input-part: "cache:rev-branch-cache" supported
+  bundle2-input-part: "cache:rev-branch-cache" (advisory) supported
   bundle2-input-part: total payload size 74
   truncating cache/rbc-revs-v1 to 56
   bundle2-input-part: "phase-heads" supported
