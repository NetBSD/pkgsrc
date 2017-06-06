$NetBSD: patch-Makefile.PL,v 1.1 2017/06/06 14:22:36 ryoon Exp $

* Workaround for Perl 5.26.0

--- Makefile.PL.orig	2014-04-24 14:50:29.000000000 +0000
+++ Makefile.PL
@@ -2,6 +2,8 @@ use 5.006;
 use strict;
 use warnings;
 
+use FindBin;
+use lib $FindBin::Bin;
 use ExtUtils::CBuilder;
 use ExtUtils::MakeMaker;
 use Getopt::Long qw( GetOptionsFromArray );
