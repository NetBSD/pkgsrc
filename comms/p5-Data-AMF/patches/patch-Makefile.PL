$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:31:37 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2010-07-21 02:45:08.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 name 'Data-AMF';
 all_from 'lib/Data/AMF.pm';
