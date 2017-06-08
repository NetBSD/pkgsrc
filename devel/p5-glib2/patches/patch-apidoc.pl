$NetBSD: patch-apidoc.pl,v 1.1 2017/06/08 00:17:24 ryoon Exp $

* Fix build with Perl 5.26.0

--- apidoc.pl.orig	2012-01-06 06:26:40.000000000 +0000
+++ apidoc.pl
@@ -1,5 +1,8 @@
 #!/usr/bin/perl -w
 
+use FindBin;
+use lib $FindBin::Bin;
+
 $header = shift @ARGV;
 $footer = shift @ARGV;
 $data   = shift @ARGV;
