$NetBSD: patch-tests_test-http-bad-server.t,v 1.1 2018/05/25 13:04:56 joerg Exp $

Merge 326b174c6a47 from upstream:
bundle2: mark the bundle2 part as advisory (issue5872)

--- tests/test-http-bad-server.t.orig	2018-05-05 23:02:58.000000000 +0000
+++ tests/test-http-bad-server.t
@@ -857,7 +857,7 @@ This is before the 0 size chunked transf
   write(41 from 41) -> (125) 23\\r\\n\x08LISTKEYS\x00\x00\x00\x02\x01\x00		namespacebookmarks\\r\\n (esc)
   write(9 from 9) -> (116) 4\\r\\n\x00\x00\x00\x00\\r\\n (esc)
   write(9 from 9) -> (107) 4\\r\\n\x00\x00\x00\x1d\\r\\n (esc)
-  write(35 from 35) -> (72) 1d\\r\\n\x16CACHE:REV-BRANCH-CACHE\x00\x00\x00\x03\x00\x00\\r\\n (esc)
+  write(35 from 35) -> (72) 1d\\r\\n\x16cache:rev-branch-cache\x00\x00\x00\x03\x00\x00\\r\\n (esc)
   write(9 from 9) -> (63) 4\\r\\n\x00\x00\x00'\\r\\n (esc)
   write(45 from 45) -> (18) 27\\r\\n\x00\x00\x00\x07\x00\x00\x00\x01\x00\x00\x00\x00default\x96\xee\x1dsT\xc4\xadsr\x04vr\xc3j\x1fV\x1e:jL\\r\\n (esc)
   write(9 from 9) -> (9) 4\\r\\n\x00\x00\x00\x00\\r\\n (esc)
@@ -901,7 +901,7 @@ Server sends a size 0 chunked-transfer s
   write(41 from 41) -> (128) 23\\r\\n\x08LISTKEYS\x00\x00\x00\x02\x01\x00		namespacebookmarks\\r\\n (esc)
   write(9 from 9) -> (119) 4\\r\\n\x00\x00\x00\x00\\r\\n (esc)
   write(9 from 9) -> (110) 4\\r\\n\x00\x00\x00\x1d\\r\\n (esc)
-  write(35 from 35) -> (75) 1d\\r\\n\x16CACHE:REV-BRANCH-CACHE\x00\x00\x00\x03\x00\x00\\r\\n (esc)
+  write(35 from 35) -> (75) 1d\\r\\n\x16cache:rev-branch-cache\x00\x00\x00\x03\x00\x00\\r\\n (esc)
   write(9 from 9) -> (66) 4\\r\\n\x00\x00\x00'\\r\\n (esc)
   write(45 from 45) -> (21) 27\\r\\n\x00\x00\x00\x07\x00\x00\x00\x01\x00\x00\x00\x00default\x96\xee\x1dsT\xc4\xadsr\x04vr\xc3j\x1fV\x1e:jL\\r\\n (esc)
   write(9 from 9) -> (12) 4\\r\\n\x00\x00\x00\x00\\r\\n (esc)
