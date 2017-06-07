$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:46:58 ryoon Exp $

--- Makefile.PL.orig	2009-12-27 23:37:51.000000000 +0000
+++ Makefile.PL
@@ -1,6 +1,8 @@
 use strict;
 use warnings;
 use ExtUtils::MakeMaker;
+use FindBin;
+use lib $FindBin::Bin;
 use inc::ExtUtils::MY_Metafile qw(my_metafile);
 
 my_metafile {
