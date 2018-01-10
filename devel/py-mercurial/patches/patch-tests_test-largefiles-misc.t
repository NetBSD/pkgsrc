$NetBSD: patch-tests_test-largefiles-misc.t,v 1.1 2018/01/10 19:32:13 wiz Exp $

From upstream:
tests: write and use a custom helper script to avoid find's -printf.

--- tests/test-largefiles-misc.t.orig	2017-12-01 19:49:46.000000000 +0000
+++ tests/test-largefiles-misc.t
@@ -1095,8 +1095,7 @@ largefiles (issue4547)
 Move (and then undo) a directory move with only largefiles.
 
   $ listtree() {
-  >   find $@ \( -type d -printf "%p/\n" -o -type f -printf "%p\n" \) \
-  >           -a -name .hg -prune | sort
+  >   $PYTHON $TESTDIR/list-tree.py $@
   > }
 
   $ cd subrepo-root
