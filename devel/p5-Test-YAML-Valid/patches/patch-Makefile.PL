$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:42:26 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2010-01-09 07:23:26.000000000 +0000
+++ Makefile.PL
@@ -1,5 +1,7 @@
 use strict;
 use warnings;
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 name('Test-YAML-Valid');
