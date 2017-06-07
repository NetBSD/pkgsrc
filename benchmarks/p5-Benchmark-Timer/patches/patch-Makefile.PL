$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:29:59 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2015-04-26 22:40:24.000000000 +0000
+++ Makefile.PL
@@ -5,6 +5,8 @@ use strict;
 # For PRIVATE Module::Install extensions
 use lib 'private-lib';
 
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 all_from('lib/Benchmark/Timer.pm');
