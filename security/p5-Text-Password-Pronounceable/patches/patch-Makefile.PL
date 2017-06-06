$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 00:10:55 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2010-08-16 19:06:43.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 version_from('lib/Text/Password/Pronounceable.pm');
