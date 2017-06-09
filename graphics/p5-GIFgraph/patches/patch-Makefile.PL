$NetBSD: patch-Makefile.PL,v 1.1 2017/06/09 16:43:16 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	1999-12-30 04:13:34.000000000 +0000
+++ Makefile.PL
@@ -3,5 +3,6 @@
  
 #--- Distribution section ---
-
+use FindBin;
+use lib $FindBin::Bin;
 use ExtUtils::MakeMaker;
 
