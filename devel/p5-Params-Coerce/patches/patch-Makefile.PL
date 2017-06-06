$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 00:28:24 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2006-10-10 05:11:03.000000000 +0000
+++ Makefile.PL
@@ -1,4 +1,6 @@
 use strict;
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 name           'Params-Coerce';
