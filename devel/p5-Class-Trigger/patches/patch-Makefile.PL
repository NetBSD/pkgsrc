$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:42:24 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2009-03-10 22:09:11.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 name 'Class-Trigger';
 all_from 'lib/Class/Trigger.pm';
