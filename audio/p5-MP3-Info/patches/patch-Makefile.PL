$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:28:46 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2007-01-04 21:41:06.000000000 +0000
+++ Makefile.PL
@@ -2,2 +2,4 @@
 
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
