$NetBSD: patch-Makefile.PL,v 1.1 2017/06/08 22:35:46 schmonz Exp $

Fix build with Perl 5.26.0.

--- Makefile.PL.orig	2011-01-28 21:47:39.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,4 @@
+BEGIN { push @INC, '.'; }
 use inc::Module::Install;
 name 'Feed-Find';
 all_from 'lib/Feed/Find.pm';
