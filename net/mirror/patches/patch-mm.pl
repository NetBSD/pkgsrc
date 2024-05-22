$NetBSD: patch-mm.pl,v 1.1 2024/05/22 09:46:12 bouyer Exp $
Fix error with newer perl

--- mm.pl.orig	2024-05-22 11:35:30.653494300 +0200
+++ mm.pl	2024-05-22 11:35:52.298166348 +0200
@@ -94,7 +94,7 @@
 
 	# only both with -flag's
 	if( $arg !~ /^-/ ){
-		unshift( ARGV, $arg );
+		unshift( @ARGV, $arg );
 		last;
 	}
 
