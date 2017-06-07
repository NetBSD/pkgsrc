$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:34:47 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2016-06-20 06:55:46.000000000 +0000
+++ Makefile.PL
@@ -2,6 +2,8 @@ use strict;
 use warnings;
 
 use 5.008001;
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install 1.06;
 BEGIN { makemaker_args( NORECURS => 1 ) } # needs to happen early for old EUMM
 
