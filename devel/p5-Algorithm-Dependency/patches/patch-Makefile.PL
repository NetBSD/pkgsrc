$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 00:34:15 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2009-04-14 09:15:37.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install::DSL 0.83;
 
 all_from       lib/Algorithm/Dependency.pm
