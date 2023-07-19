$NetBSD: patch-tests_test-bundle-phase-internal.t,v 1.1 2023/07/19 14:40:50 wiz Exp $

https://bz.mercurial-scm.org/show_bug.cgi?id=6835

--- tests/test-bundle-phase-internal.t.orig	2023-07-06 14:04:17.000000000 +0000
+++ tests/test-bundle-phase-internal.t
@@ -99,7 +99,7 @@ backup bundle from strip
 strip an ancestors of the internal changeset
 --------------------------------------------
 
-  $ cp -ar reference-repo strip-ancestor
+  $ cp -aR reference-repo strip-ancestor
   $ cd strip-ancestor
 
 The internal change is stripped, yet it should be skipped from the backup bundle.
@@ -154,7 +154,7 @@ Shelve should still work
 strip an unrelated changeset with a lower revnum
 ------------------------------------------------
 
-  $ cp -ar reference-repo strip-unrelated
+  $ cp -aR reference-repo strip-unrelated
   $ cd strip-unrelated
 
 The internal change is not directly stripped, but it is affected by the strip
@@ -200,7 +200,7 @@ Shelve should still work
 explicitly strip the internal changeset
 ---------------------------------------
 
-  $ cp -ar reference-repo strip-explicit
+  $ cp -aR reference-repo strip-explicit
   $ cd strip-explicit
 
 The internal change is directly selected for stripping.
