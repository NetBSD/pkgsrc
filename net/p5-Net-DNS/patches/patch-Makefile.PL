$NetBSD: patch-Makefile.PL,v 1.1 2013/08/15 16:36:11 joerg Exp $

--- Makefile.PL.orig	2013-08-15 16:24:21.000000000 +0000
+++ Makefile.PL
@@ -191,7 +191,7 @@ unless ( defined $use_xs ) {
 	if ( test_cc() ) {
 		print "You have a working compiler.\n";
 		$use_xs = 1;
-		$Makefile{'MYEXTLIB'} = 'netdns$(LIB_EXT)';
+		$Makefile{'MYEXTLIB'} = '';
 	} else {
 		$use_xs = 0;
 		$Makefile{'MYEXTLIB'} = '';
