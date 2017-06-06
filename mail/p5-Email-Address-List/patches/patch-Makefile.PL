$NetBSD: patch-Makefile.PL,v 1.1 2017/06/06 14:48:44 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2014-01-28 21:55:43.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 all_from 'lib/Email/Address/List.pm';
 readme_from 'lib/Email/Address/List.pm';
