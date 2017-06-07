$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:42:26 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2014-01-08 21:34:38.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 name           'Test-utf8';
