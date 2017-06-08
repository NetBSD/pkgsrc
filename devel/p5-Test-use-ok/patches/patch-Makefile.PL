$NetBSD: patch-Makefile.PL,v 1.1 2017/06/08 12:57:15 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2012-09-11 18:23:06.000000000 +0000
+++ Makefile.PL
@@ -1,4 +1,6 @@
 #!/usr/bin/perl
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Package 'Au:dry';
 all_from 'lib/Test/use/ok.pm';
 __END__
