$NetBSD: patch-Build.PL,v 1.1 2017/06/06 23:58:52 ryoon Exp $

* Fix build with Perl 5.26.0

--- Build.PL.orig	2015-08-25 02:10:50.000000000 +0000
+++ Build.PL
@@ -9,6 +9,8 @@ use strict;
 use warnings;
 use utf8;
 
+use FindBin;
+use lib $FindBin::Bin;
 use builder::MyBuilder;
 use File::Basename;
 use File::Spec;
