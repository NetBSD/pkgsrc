$NetBSD: patch-Makefile.PL,v 1.1 2017/06/09 16:55:10 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2002-04-18 02:07:52.000000000 +0000
+++ Makefile.PL
@@ -1,5 +1,7 @@
 #!/usr/bin/perl
 
+use FindBin;
+use lib $FindBin::Bin;
 use ExtUtils::MakeMaker;
 
 WriteMakefile(
