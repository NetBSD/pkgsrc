$NetBSD: patch-tests_test-convert-cvs.t,v 1.3 2021/04/11 22:55:42 wiz Exp $

Fix python interpreter.
https://bz.mercurial-scm.org/show_bug.cgi?id=6480

--- tests/test-convert-cvs.t.orig	2021-03-09 05:48:58.000000000 +0000
+++ tests/test-convert-cvs.t
@@ -521,7 +521,7 @@ Commit messages of version 1.2 - 1.4 use
 |cp932     |\x82\xa0      |  x      x     o    |
 
   $ mkdir -p cvsrepo/transcoding
-  $ python <<EOF
+  $ $PYTHON <<EOF
   > fp = open('cvsrepo/transcoding/file,v', 'wb')
   > fp.write((b'''
   > head	1.4;
