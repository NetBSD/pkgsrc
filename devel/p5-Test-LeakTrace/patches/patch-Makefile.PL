$NetBSD: patch-Makefile.PL,v 1.1 2017/06/06 14:27:23 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2014-11-13 22:40:34.000000000 +0000
+++ Makefile.PL
@@ -1,5 +1,7 @@
 use strict;
 use warnings;
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 name 'Test-LeakTrace';
