$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:42:25 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2009-07-10 11:33:17.000000000 +0000
+++ Makefile.PL
@@ -1,5 +1,7 @@
 #! /usr/bin/perl -w
 
+use FindBin;
+use lib $FindBin::Bin;
 # Load the Module::Install bundled in ./inc/
 use inc::Module::Install;
 
