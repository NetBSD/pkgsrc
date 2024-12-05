$NetBSD: patch-git-core_ci_run-test-slice.sh,v 1.1 2024/12/05 01:19:27 riastradh Exp $

Shell portability fix.

--- git-core/ci/run-test-slice.sh.orig	2024-09-24 11:39:58.000000000 +0000
+++ git-core/ci/run-test-slice.sh
@@ -11,7 +11,7 @@ group "Run tests" make --quiet -C t T="$
 handle_failed_tests
 
 # We only have one unit test at the moment, so run it in the first slice
-if [ "$1" == "0" ] ; then
+if [ "$1" = "0" ] ; then
 	group "Run unit tests" make --quiet -C t unit-tests-test-tool
 fi
 
