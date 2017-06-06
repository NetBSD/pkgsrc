$NetBSD: patch-Makefile.PL,v 1.1 2017/06/06 15:19:11 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2015-04-28 00:46:01.000000000 +0000
+++ Makefile.PL
@@ -1,4 +1,6 @@
 use strict;
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 name('Class-Accessor-Lite');
