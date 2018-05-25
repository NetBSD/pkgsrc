$NetBSD: patch-tests_test-lfs-serve-access.t,v 1.1 2018/05/25 13:04:56 joerg Exp $

Merge 326b174c6a47 from upstream:
bundle2: mark the bundle2 part as advisory (issue5872)

--- tests/test-lfs-serve-access.t.orig	2018-05-05 23:02:58.000000000 +0000
+++ tests/test-lfs-serve-access.t
@@ -93,7 +93,7 @@ Blob URIs are correct when --prefix is u
   bundle2-input-part: "listkeys" (params: 1 mandatory) supported
   bundle2-input-part: "phase-heads" supported
   bundle2-input-part: total payload size 24
-  bundle2-input-part: "cache:rev-branch-cache" supported
+  bundle2-input-part: "cache:rev-branch-cache" (advisory) supported
   bundle2-input-part: total payload size 39
   bundle2-input-bundle: 3 parts total
   checking for updated bookmarks
