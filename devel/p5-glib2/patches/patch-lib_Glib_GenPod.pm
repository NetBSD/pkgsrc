$NetBSD: patch-lib_Glib_GenPod.pm,v 1.1 2017/06/08 00:17:24 ryoon Exp $

* Fix build with Perl 5.26.0

--- lib/Glib/GenPod.pm.orig	2016-09-28 04:03:20.000000000 +0000
+++ lib/Glib/GenPod.pm
@@ -18,6 +18,9 @@ use File::Spec;
 use Data::Dumper;
 use POSIX qw(strftime);
 
+use FindBin;
+use lib $FindBin::Bin;
+
 use Glib;
 
 use base 'Exporter';
