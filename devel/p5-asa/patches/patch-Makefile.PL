$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:42:26 ryoon Exp $

--- Makefile.PL.orig	2011-03-06 22:51:11.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install::DSL;
 
 all_from      lib/asa.pm
