$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:56:57 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2015-02-17 00:57:03.000000000 +0000
+++ Makefile.PL
@@ -1,5 +1,7 @@
 use strict;
 use warnings;
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 print "which gpg ... ";
