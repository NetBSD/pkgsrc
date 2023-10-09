$NetBSD: patch-tests_test-remotefilelog-gc.t,v 1.1 2023/10/09 19:01:03 wiz Exp $

Test fix from upstream
https://foss.heptapod.net/mercurial/mercurial-devel/-/merge_requests/675/

--- tests/test-remotefilelog-gc.t.orig	2023-09-06 16:11:09.000000000 +0000
+++ tests/test-remotefilelog-gc.t
@@ -106,11 +106,6 @@
 # Test that warning is displayed when the repo path is malformed
 
   $ printf "asdas\0das" >> $CACHEDIR/repos
-#if py311
-  $ hg gc
-  finished: removed 0 of 4 files (0.00 GB to 0.00 GB)
-#else
   $ hg gc
   abort: invalid path asdas\x00da: .*(null|NULL).* (re)
   [255]
-#endif
