$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 00:12:53 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2015-02-20 17:50:45.000000000 +0000
+++ Makefile.PL
@@ -1,4 +1,6 @@
 use 5.006;
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 all_from 'lib/Text/Quoted.pm';
