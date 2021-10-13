$NetBSD: patch-tests_test-persistent-nodemap.t,v 1.1 2021/10/13 12:35:29 wiz Exp $

Fix test failure
https://bz.mercurial-scm.org/show_bug.cgi?id=6523

--- tests/test-persistent-nodemap.t.orig	2021-10-05 15:47:21.000000000 +0000
+++ tests/test-persistent-nodemap.t
@@ -1028,9 +1028,10 @@ truncate the file
   $ datafilepath=`ls corruption-test-repo/.hg/store/00changelog*.nd`
   $ f -s $datafilepath
   corruption-test-repo/.hg/store/00changelog-*.nd: size=121088 (glob)
-  $ dd if=$datafilepath bs=1000 count=10 of=$datafilepath-tmp status=noxfer
+  $ dd if=$datafilepath bs=1000 count=10 of=$datafilepath-tmp
   10+0 records in
   10+0 records out
+  * bytes transferred in * (glob)
   $ mv $datafilepath-tmp $datafilepath
   $ f -s $datafilepath
   corruption-test-repo/.hg/store/00changelog-*.nd: size=10000 (glob)
