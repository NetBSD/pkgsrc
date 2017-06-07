$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:33:24 ryoon Exp $

* FIx build with Perl 5.26.0

--- Makefile.PL.orig	2016-12-03 00:33:01.000000000 +0000
+++ Makefile.PL
@@ -6,7 +6,7 @@ my $clean = {};
 if (-f "Collate.xs") {
     print "Making header files for XS...\n";
 
-    do 'mkheader' or die $@ || "mkheader: $!";
+    do './mkheader' or die $@ || "mkheader: $!";
 
     $clean = { FILES => 'ucatbl.h' };
 }
