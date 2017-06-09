$NetBSD: patch-grab_it_tv__grab__it.PL,v 1.1 2017/06/09 16:51:00 ryoon Exp $

* Fix build with Perl 5.26.0

--- grab/it/tv_grab_it.PL.orig	2009-05-19 21:03:05.000000000 +0000
+++ grab/it/tv_grab_it.PL
@@ -357,7 +357,7 @@ close IN_FH or die "cannot close $in: $!
 
 # stuff for setting share dir
 die "usage: $_ output_file share_dir" if @ARGV != 2;
-require 'lib/set_share_dir.pl';
+require './lib/set_share_dir.pl';
 #warn "faccio $ARGV[0] $ARGV[1]\n";
 #set_share_dir('grab/it/tv_grab_it.in2', $ARGV[0], $ARGV[1]);
 copy( 'grab/it/tv_grab_it.in2', $ARGV[0] );
