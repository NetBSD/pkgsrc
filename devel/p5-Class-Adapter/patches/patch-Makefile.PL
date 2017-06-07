$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:42:24 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2011-03-24 01:38:45.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install::DSL 1.00;
 
 all_from      lib/Class/Adapter.pm
