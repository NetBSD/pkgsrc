$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:31:37 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2011-11-09 02:40:00.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install::DSL 1.04;
 
 all_from      lib/SMS/Send.pm
