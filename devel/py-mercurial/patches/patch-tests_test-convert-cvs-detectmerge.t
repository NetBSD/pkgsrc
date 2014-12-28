$NetBSD: patch-tests_test-convert-cvs-detectmerge.t,v 1.1 2014/12/28 17:16:54 wiz Exp $

Fix cvs-specific tests with cvs-1.12.
http://bz.selenic.com/show_bug.cgi?id=4482

--- tests/test-convert-cvs-detectmerge.t.orig	2014-12-18 20:59:22.000000000 +0000
+++ tests/test-convert-cvs-detectmerge.t
@@ -31,7 +31,6 @@ XXX copied from test-convert-cvs-synthet
 
 create cvs repository with one project
 
-  $ mkdir cvsrepo
   $ cvscall -q -d "$CVSROOT" init
   $ mkdir cvsrepo/proj
 
