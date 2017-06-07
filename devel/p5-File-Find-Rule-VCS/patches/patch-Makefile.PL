$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:42:25 ryoon Exp $

--- Makefile.PL.orig	2010-10-06 00:48:31.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install::DSL 1.00;
 
 all_from      lib/File/Find/Rule/VCS.pm
