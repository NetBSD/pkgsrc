$NetBSD: patch-Makefile.PL,v 1.3 2017/06/08 00:17:24 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2015-12-21 16:42:17.000000000 +0000
+++ Makefile.PL
@@ -19,6 +19,8 @@ BEGIN { require 5.008; }
 
 use strict;
 use warnings;
+use FindBin;
+use lib $FindBin::Bin;
 use ExtUtils::MakeMaker;
 use File::Spec;
 use Cwd;
