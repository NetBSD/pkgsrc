$NetBSD: patch-filter_tv__grep.PL,v 1.1 2017/06/09 16:51:00 ryoon Exp $

* Fix build with Perl 5.26.0

--- filter/tv_grep.PL.orig	2006-06-03 19:33:46.000000000 +0000
+++ filter/tv_grep.PL
@@ -12,7 +12,7 @@
 
 use IO::File;
 use XMLTV;
-require 'filter/Grep.pm';
+require './filter/Grep.pm';
 
 my $out = shift @ARGV; die "no output file given" if not defined $out;
 my $in = 'filter/tv_grep.in';
