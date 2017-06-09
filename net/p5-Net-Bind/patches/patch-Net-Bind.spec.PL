$NetBSD: patch-Net-Bind.spec.PL,v 1.1 2017/06/09 16:55:10 ryoon Exp $

* Fix build with Perl 5.26.0

--- Net-Bind.spec.PL.orig	2002-04-18 01:56:57.000000000 +0000
+++ Net-Bind.spec.PL
@@ -29,7 +29,7 @@ sub WriteMakefile {
     die "Makefile.PL: Could not determine version!";
   }
 }
-do "Makefile.PL";
+do "./Makefile.PL";
 if ($name) {
   $name =~ s/::/-/g;
 } else {
