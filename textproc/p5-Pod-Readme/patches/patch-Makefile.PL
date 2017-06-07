$NetBSD: patch-Makefile.PL,v 1.2 2017/06/07 14:46:58 ryoon Exp $

* Fix build with Perl 5.26.0
* do not install depends via CPAN

--- Makefile.PL.orig	2014-12-08 18:01:19.000000000 +0000
+++ Makefile.PL
@@ -1,5 +1,7 @@
 use strict;
 use warnings FATAL => 'all';
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 author 'Robert Rothenberg <rrwo@cpan.org>';
@@ -89,5 +91,5 @@ author_requires(
 recursive_author_tests('xt');
 
 install_as_cpan;
-auto_install;
+#auto_install;
 WriteAll;
