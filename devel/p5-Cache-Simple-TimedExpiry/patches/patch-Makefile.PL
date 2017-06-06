$NetBSD: patch-Makefile.PL,v 1.1 2017/06/06 14:51:04 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2006-08-18 19:51:03.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+           use FindBin;
+           use lib $FindBin::Bin;
            use inc::Module::Install;
 
            name            ('Cache-Simple-TimedExpiry');
