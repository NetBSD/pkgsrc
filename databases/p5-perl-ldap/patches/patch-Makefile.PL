$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:34:47 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2015-04-02 12:43:37.000000000 +0000
+++ Makefile.PL
@@ -1,5 +1,7 @@
 # -*- perl -*-
 
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 perl_version    5.008001;
