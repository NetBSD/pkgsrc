$NetBSD: patch-Makefile.PL,v 1.1 2015/01/11 15:29:44 wen Exp $
do not install depends via CPAN
--- Makefile.PL.orig	2015-01-11 23:14:38.000000000 +0000
+++ Makefile.PL
@@ -89,5 +89,5 @@ author_requires(
 recursive_author_tests('xt');
 
 install_as_cpan;
-auto_install;
+#auto_install;
 WriteAll;
