$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:42:25 ryoon Exp $

--- Makefile.PL.orig	2014-05-13 08:29:18.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 all_from 'lib/Parallel/Prefork.pm';
