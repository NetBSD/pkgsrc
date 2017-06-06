$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 00:25:39 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2006-09-11 11:20:55.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 use warnings;
 use strict;
