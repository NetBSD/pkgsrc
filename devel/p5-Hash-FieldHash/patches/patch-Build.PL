$NetBSD: patch-Build.PL,v 1.1 2017/06/08 12:57:15 ryoon Exp $

* Fix build with Perl 5.26.0

--- Build.PL.orig	2017-02-06 01:10:17.000000000 +0000
+++ Build.PL
@@ -9,6 +9,9 @@ use strict;
 use warnings;
 use utf8;
 
+use FindBin;
+use lib $FindBin::Bin;
+
 use builder::MyBuilder;
 use File::Basename;
 use File::Spec;
