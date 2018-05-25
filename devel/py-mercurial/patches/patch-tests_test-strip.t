$NetBSD: patch-tests_test-strip.t,v 1.1 2018/05/25 13:04:56 joerg Exp $

Merge 326b174c6a47 from upstream:
bundle2: mark the bundle2 part as advisory (issue5872)

--- tests/test-strip.t.orig	2018-05-05 23:02:58.000000000 +0000
+++ tests/test-strip.t
@@ -851,7 +851,7 @@ check strip behavior
   d8db9d1372214336d2b5570f20ee468d2c72fa8b
   bundle2-output-bundle: "HG20", (1 params) 3 parts total
   bundle2-output-part: "changegroup" (params: 1 mandatory 1 advisory) streamed payload
-  bundle2-output-part: "cache:rev-branch-cache" streamed payload
+  bundle2-output-part: "cache:rev-branch-cache" (advisory) streamed payload
   bundle2-output-part: "phase-heads" 24 bytes payload
   saved backup bundle to $TESTTMP/issue4736/.hg/strip-backup/6625a5168474-345bb43d-backup.hg
   updating the branch cache
