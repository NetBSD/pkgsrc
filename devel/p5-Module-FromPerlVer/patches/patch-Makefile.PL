$NetBSD: patch-Makefile.PL,v 1.2 2018/03/18 08:44:00 wiz Exp $

Fix path to env(1).
https://rt.cpan.org/Ticket/Display.html?id=124776

--- Makefile.PL.orig	2018-03-17 23:15:15.000000000 +0000
+++ Makefile.PL
@@ -37,7 +37,7 @@ for my $base 
 
     print "Setup: '$path'";
 
-    system "/bin/env perl $path";
+    system "/usr/bin/env perl $path";
     my $err = $!;
 
     print "$path fails: $err"
