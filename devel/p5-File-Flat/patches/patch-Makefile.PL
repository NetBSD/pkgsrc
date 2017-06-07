$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:42:25 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2008-03-24 05:20:01.000000000 +0000
+++ Makefile.PL
@@ -1,4 +1,6 @@
 use strict;
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 # Because many filesystem modules are buggier
