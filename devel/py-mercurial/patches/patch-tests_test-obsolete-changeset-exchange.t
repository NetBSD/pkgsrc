$NetBSD: patch-tests_test-obsolete-changeset-exchange.t,v 1.1 2018/05/25 13:04:56 joerg Exp $

Merge 326b174c6a47 from upstream:
bundle2: mark the bundle2 part as advisory (issue5872)

--- tests/test-obsolete-changeset-exchange.t.orig	2018-05-05 23:02:58.000000000 +0000
+++ tests/test-obsolete-changeset-exchange.t
@@ -159,7 +159,7 @@ client only pulls down 1 changeset
   bundle2-output-part: "changegroup" (params: 1 mandatory 1 advisory) streamed payload
   bundle2-output-part: "listkeys" (params: 1 mandatory) empty payload
   bundle2-output-part: "phase-heads" 24 bytes payload
-  bundle2-output-part: "cache:rev-branch-cache" streamed payload
+  bundle2-output-part: "cache:rev-branch-cache" (advisory) streamed payload
   bundle2-input-bundle: with-transaction
   bundle2-input-part: "changegroup" (params: 1 mandatory 1 advisory) supported
   adding changesets
@@ -172,7 +172,7 @@ client only pulls down 1 changeset
   bundle2-input-part: "listkeys" (params: 1 mandatory) supported
   bundle2-input-part: "phase-heads" supported
   bundle2-input-part: total payload size 24
-  bundle2-input-part: "cache:rev-branch-cache" supported
+  bundle2-input-part: "cache:rev-branch-cache" (advisory) supported
   bundle2-input-part: total payload size 39
   bundle2-input-bundle: 3 parts total
   checking for updated bookmarks
