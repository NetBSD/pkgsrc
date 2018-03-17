$NetBSD: patch-Makefile.PL,v 1.1 2018/03/17 07:46:15 wiz Exp $

Fix path to env(1).
https://rt.cpan.org/Ticket/Display.html?id=124776

--- Makefile.PL.orig	2018-03-16 01:09:46.000000000 +0000
+++ Makefile.PL
@@ -36,7 +36,7 @@ for my $base 
 
     print "Setup: '$path'";
 
-    system "/bin/env perl $path";
+    system "/usr/bin/env perl $path";
     my $err = $!;
 
     print "$path fails: $err"
