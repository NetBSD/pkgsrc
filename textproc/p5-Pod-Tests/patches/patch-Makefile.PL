$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:46:58 ryoon Exp $

* FIx build with Perl 5.26.0

--- Makefile.PL.orig	2008-07-13 08:35:49.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install 0.75;
 
 all_from       'lib/Pod/Tests.pm';
