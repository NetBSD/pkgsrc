$NetBSD: patch-Makefile.PL,v 1.1 2013/07/13 18:12:11 schmonz Exp $

Use pkgsrc's sqlite for portability.

--- Makefile.PL.orig	2013-05-31 04:30:29.000000000 +0000
+++ Makefile.PL
@@ -125,7 +125,7 @@ SCOPE: {
 # a system sqlite is also sophisticated enough to have a patching system
 # that can change the if ( 0 ) to if ( 1 )
 my ($sqlite_local, $sqlite_base, $sqlite_lib, $sqlite_inc);
-if ( 0 ) {
+if ( 1 ) {
 	require File::Spec;
 	if ( $sqlite_base = (grep(/SQLITE_LOCATION=.*/, @ARGV))[0] ) {
 		$sqlite_base =~ /=(.*)/;
