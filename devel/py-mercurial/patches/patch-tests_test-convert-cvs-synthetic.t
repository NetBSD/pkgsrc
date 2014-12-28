$NetBSD: patch-tests_test-convert-cvs-synthetic.t,v 1.1 2014/12/28 17:16:54 wiz Exp $

Fix cvs-specific tests with cvs-1.12.
http://bz.selenic.com/show_bug.cgi?id=4482

--- tests/test-convert-cvs-synthetic.t.orig	2014-12-18 20:59:22.000000000 +0000
+++ tests/test-convert-cvs-synthetic.t
@@ -14,6 +14,7 @@ create cvs repository with one project
   $ CVS_OPTIONS=-f
   $ export CVS_OPTIONS
   $ cd ..
+  $ rmdir cvsrepo
   $ cvscall()
   > {
   >     cvs -f "$@"
