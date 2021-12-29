$NetBSD: patch-build-aux_testrunner.sh,v 1.1 2021/12/29 16:31:40 adam Exp $

Fix typo.

--- build-aux/testrunner.sh.orig	2021-12-29 16:14:56.402846115 +0000
+++ build-aux/testrunner.sh
@@ -190,7 +190,7 @@ cd $testdir
 case "$testfile" in
 *.gs)
 	SOURCEFILE=$testpath.gs
-	;&
+	;;
 *.vala)
 	SOURCEFILE=${SOURCEFILE:-$testpath.vala}
 	cat "$abs_srcdir/$testfile" > ./$SOURCEFILE
