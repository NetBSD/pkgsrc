$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 00:08:37 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2013-07-03 23:17:50.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 all_from('lib/Symbol/Global/Name.pm');
