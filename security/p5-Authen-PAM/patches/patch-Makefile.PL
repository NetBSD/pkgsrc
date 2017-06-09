$NetBSD: patch-Makefile.PL,v 1.1 2017/06/09 16:57:55 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2005-06-06 13:29:12.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use ExtUtils::MakeMaker;
 use Config;
 
