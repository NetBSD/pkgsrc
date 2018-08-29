$NetBSD: patch-Makefile.PL,v 1.1 2018/08/29 06:15:46 wiz Exp $

Fix:
Bareword "use_test_base" not allowed while "strict subs" in use at Makefile.PL line 17.

--- Makefile.PL.orig	2013-05-18 11:02:25.000000000 +0000
+++ Makefile.PL
@@ -14,6 +14,5 @@ test_requires(
     'Module::Install::AuthorTests' => 0,
 );
 
-use_test_base;
 auto_include;
 WriteAll;
