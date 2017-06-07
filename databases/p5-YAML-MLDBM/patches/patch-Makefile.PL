$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:34:47 ryoon Exp $

--- Makefile.PL.orig	2003-02-02 05:02:07.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use CPAN::MakeMaker;
 
 $PREREQ_PM{YAML}       = '0.35';
