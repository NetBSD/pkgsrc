$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:42:23 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2010-10-08 00:00:09.000000000 +0000
+++ Makefile.PL
@@ -1,5 +1,7 @@
 sub auto_set_repository {}
 
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 name 'Array-Diff';
 all_from 'lib/Array/Diff.pm';
