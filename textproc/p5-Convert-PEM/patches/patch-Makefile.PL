$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:46:58 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2010-12-07 04:53:22.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 name 'Convert-PEM';
 all_from 'lib/Convert/PEM.pm';
