$NetBSD: patch-Makefile.PL,v 1.1 2017/06/09 16:43:15 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2015-01-21 01:05:58.000000000 +0000
+++ Makefile.PL
@@ -3,6 +3,8 @@
 use 5.006;
 use strict;
 use warnings;
+use FindBin;
+use lib $FindBin::Bin;
 use lib qw( builder/lib );
 use Build::Spec qw( mm_spec );
 use ExtUtils::MakeMaker;
