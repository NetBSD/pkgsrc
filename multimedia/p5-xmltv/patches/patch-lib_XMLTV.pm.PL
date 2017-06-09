$NetBSD: patch-lib_XMLTV.pm.PL,v 1.1 2017/06/09 16:51:00 ryoon Exp $

* Fix build with Perl 5.26.0

--- lib/XMLTV.pm.PL.orig	2006-06-03 19:26:34.000000000 +0000
+++ lib/XMLTV.pm.PL
@@ -8,7 +8,7 @@ use strict;
 sub print_list( $$ );
 
 my $out = shift @ARGV; die "no output file given" if not defined $out;
-my $in = 'lib/XMLTV.pm.in';
+my $in = './lib/XMLTV.pm.in';
 require $in;
 open(IN_FH, $in) or die "cannot read $in: $!";
 die if not @XMLTV::Channel_Handlers; die if not @XMLTV::Programme_Handlers;
