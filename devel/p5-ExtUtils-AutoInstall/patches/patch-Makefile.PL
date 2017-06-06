$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 00:36:24 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2005-09-09 12:07:24.000000000 +0000
+++ Makefile.PL
@@ -1,5 +1,7 @@
 #!/usr/bin/perl
 
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 use lib 'lib';
 
