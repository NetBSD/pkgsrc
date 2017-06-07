$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:33:24 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2015-12-16 02:02:23.000000000 +0000
+++ Makefile.PL
@@ -8,7 +8,7 @@ my $mm_ver = ExtUtils::MakeMaker->VERSIO
 if (-f "Normalize.xs") {
     print STDERR "Making header files for XS...\n";
 
-    do 'mkheader' or die $@ || "mkheader: $!";
+    do './mkheader' or die $@ || "mkheader: $!";
 
     $clean = { FILES => 'unfcan.h unfcmb.h unfcmp.h unfcpt.h unfexc.h' };
 }
