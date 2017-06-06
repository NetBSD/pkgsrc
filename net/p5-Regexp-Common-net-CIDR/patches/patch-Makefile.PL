$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 00:05:50 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2015-06-03 20:17:22.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 name('Regexp-Common-net-CIDR');
 version_from('lib/Regexp/Common/net/CIDR.pm');
