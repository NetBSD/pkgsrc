$NetBSD: patch-tests_test-hghave.t,v 1.1 2017/10/05 22:32:50 wiz Exp $

Fix for https://bz.mercurial-scm.org/show_bug.cgi?id=5697
from upstream:
https://www.mercurial-scm.org/repo/hg-committed/rev/bb14dbab4df6

--- tests/test-hghave.t.orig	2017-10-01 09:28:49.000000000 +0000
+++ tests/test-hghave.t
@@ -22,7 +22,7 @@ Testing hghave extensibility for third p
   > EOF
   $ ( \
   > testrepohgenv; \
-  > $TESTDIR/run-tests.py $HGTEST_RUN_TESTS_PURE test-hghaveaddon.t \
+  > $PYTHON $TESTDIR/run-tests.py $HGTEST_RUN_TESTS_PURE test-hghaveaddon.t \
   > )
   .
   # Ran 1 tests, 0 skipped, 0 failed.
