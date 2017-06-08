$NetBSD: patch-Makefile.PL,v 1.1 2017/06/08 14:05:17 schmonz Exp $

Fix build with Perl 5.26.0.

--- Makefile.PL.orig	2014-03-22 05:49:14.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+# Load the Module::Install bundled in ./inc/
+BEGIN { push @INC, '.'; }
 use inc::Module::Install;
 
 my @DEFINES;
