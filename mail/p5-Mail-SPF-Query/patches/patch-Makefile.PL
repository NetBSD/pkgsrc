$NetBSD: patch-Makefile.PL,v 1.1 2017/06/09 16:47:21 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2005-12-31 23:23:16.000000000 +0000
+++ Makefile.PL
@@ -1,4 +1,6 @@
 use 5.006;
+use FindBin;
+use lib $FindBin::Bin;
 use ExtUtils::MakeMaker;
 # See lib/ExtUtils/MakeMaker.pm for details of how to influence
 # the contents of the Makefile that is written.
