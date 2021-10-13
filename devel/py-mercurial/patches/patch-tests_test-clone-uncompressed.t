$NetBSD: patch-tests_test-clone-uncompressed.t,v 1.1 2021/10/13 12:35:29 wiz Exp $

Fix test.
https://bz.mercurial-scm.org/show_bug.cgi?id=6591

--- tests/test-clone-uncompressed.t.orig	2021-10-05 15:47:21.000000000 +0000
+++ tests/test-clone-uncompressed.t
@@ -96,7 +96,7 @@ Name with special characters
 
 name causing issue6581
 
-  $ mkdir --parents container/isam-build-centos7/
+  $ mkdir -p container/isam-build-centos7/
   $ touch container/isam-build-centos7/bazel-coverage-generator-sandboxfs-compatibility-0758e3e4f6057904d44399bd666faba9e7f40686.patch
 
 Add all that
