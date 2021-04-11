$NetBSD: patch-tests_test-merge-tools.t,v 1.3 2021/04/11 23:07:03 wiz Exp $

Fix python interpreter.
https://bz.mercurial-scm.org/show_bug.cgi?id=6480

--- tests/test-merge-tools.t.orig	2021-03-09 05:48:58.000000000 +0000
+++ tests/test-merge-tools.t
@@ -1921,7 +1921,7 @@ Verify naming of temporary files and tha
 Binary files capability checking
 
   $ hg update -q -C 0
-  $ python <<EOF
+  $ $PYTHON <<EOF
   > with open('b', 'wb') as fp:
   >     fp.write(b'\x00\x01\x02\x03')
   > EOF
@@ -1929,7 +1929,7 @@ Binary files capability checking
   $ hg commit -qm "add binary file (#1)"
 
   $ hg update -q -C 0
-  $ python <<EOF
+  $ $PYTHON <<EOF
   > with open('b', 'wb') as fp:
   >     fp.write(b'\x03\x02\x01\x00')
   > EOF
