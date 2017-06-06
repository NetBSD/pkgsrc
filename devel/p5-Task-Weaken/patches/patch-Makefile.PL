$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 00:23:01 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2011-03-08 14:34:12.000000000 +0000
+++ Makefile.PL
@@ -39,6 +39,8 @@
 #
 # Adam K
 
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install 1.00;
 
 all_from      'lib/Task/Weaken.pm';
