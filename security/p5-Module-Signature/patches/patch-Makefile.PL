$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:56:58 ryoon Exp $

--- Makefile.PL.orig	2016-09-05 06:31:16.000000000 +0000
+++ Makefile.PL
@@ -1,4 +1,6 @@
 use strict;
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install 0.92;
 
 $|++;
