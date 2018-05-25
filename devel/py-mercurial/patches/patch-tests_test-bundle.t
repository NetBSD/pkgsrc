$NetBSD: patch-tests_test-bundle.t,v 1.1 2018/05/25 13:04:56 joerg Exp $

Merge 326b174c6a47 from upstream:
bundle2: mark the bundle2 part as advisory (issue5872)

--- tests/test-bundle.t.orig	2018-05-05 23:02:57.000000000 +0000
+++ tests/test-bundle.t
@@ -803,7 +803,7 @@ bundle single branch
   bundling: b 1/3 files (33.33%)
   bundling: b1 2/3 files (66.67%)
   bundling: x 3/3 files (100.00%)
-  bundle2-output-part: "cache:rev-branch-cache" streamed payload
+  bundle2-output-part: "cache:rev-branch-cache" (advisory) streamed payload
 
 #if repobundlerepo
 == Test for issue3441
