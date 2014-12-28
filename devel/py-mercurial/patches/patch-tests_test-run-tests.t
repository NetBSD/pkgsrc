$NetBSD: patch-tests_test-run-tests.t,v 1.1 2014/12/28 22:47:59 wiz Exp $

Adapt glob so this works with NetBSD's /bin/sh.
http://bz.selenic.com/show_bug.cgi?id=4484

--- tests/test-run-tests.t.orig	2014-12-18 20:59:22.000000000 +0000
+++ tests/test-run-tests.t
@@ -181,22 +181,22 @@ Running In Debug Mode
 ======================
 
   $ $TESTDIR/run-tests.py --with-hg=`which hg` --debug 2>&1 | grep -v pwd
-  + echo SALT* 0 0 (glob)
-  SALT* 0 0 (glob)
+  + echo *SALT* 0 0 (glob)
+  *SALT* 0 0 (glob)
   + echo babar
   babar
-  + echo SALT* 4 0 (glob)
-  SALT* 4 0 (glob)
-  .+ echo SALT* 0 0 (glob)
-  SALT* 0 0 (glob)
+  + echo *SALT* 4 0 (glob)
+  *SALT* 4 0 (glob)
+  .+ echo *SALT* 0 0 (glob)
+  *SALT* 0 0 (glob)
   + echo babar
   babar
-  + echo SALT* 2 0 (glob)
-  SALT* 2 0 (glob)
+  + echo *SALT* 2 0 (glob)
+  *SALT* 2 0 (glob)
   + echo xyzzy
   xyzzy
-  + echo SALT* 4 0 (glob)
-  SALT* 4 0 (glob)
+  + echo *SALT* 4 0 (glob)
+  *SALT* 4 0 (glob)
   .
   # Ran 2 tests, 0 skipped, 0 warned, 0 failed.
 
