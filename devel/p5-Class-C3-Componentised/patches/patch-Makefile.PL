$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:42:24 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2011-08-07 15:29:59.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install 1.00;
 
 use 5.006002;
