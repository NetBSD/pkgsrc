$NetBSD: patch-Makefile.PL,v 1.1 2017/06/06 15:16:58 ryoon Exp $

--- Makefile.PL.orig	2011-10-26 12:37:08.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 requires( perl => '5.8.1');
 name('Module-Refresh');
