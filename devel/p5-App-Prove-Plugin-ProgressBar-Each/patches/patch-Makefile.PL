$NetBSD: patch-Makefile.PL,v 1.1 2015/01/04 06:25:14 schmonz Exp $

--- Makefile.PL.orig	2011-01-20 02:10:17.000000000 +0000
+++ Makefile.PL
@@ -7,11 +7,11 @@ requires 'TAP::Formatter::Console';
 requires 'Term::ProgressBar::Simple';
 
 tests 't/*.t';
-author_tests 'xt';
+#author_tests 'xt';
 
 test_requires 'Test::More';
 
-auto_set_repository;
+#auto_set_repository;
 auto_include;
 
 WriteAll;
