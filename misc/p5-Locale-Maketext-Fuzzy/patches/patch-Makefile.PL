$NetBSD: patch-Makefile.PL,v 1.1 2017/06/06 15:14:28 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2011-12-11 02:11:17.000000000 +0000
+++ Makefile.PL
@@ -1,2 +1,4 @@
 #!/usr/bin/env perl
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Package 'Au:dry 1';
