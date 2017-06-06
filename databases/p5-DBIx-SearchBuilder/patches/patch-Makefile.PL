$NetBSD: patch-Makefile.PL,v 1.1 2017/06/06 14:54:15 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2016-07-11 20:11:16.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 name ('DBIx-SearchBuilder');
