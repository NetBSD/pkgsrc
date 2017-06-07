$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:42:23 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2016-09-17 02:32:17.000000000 +0000
+++ Makefile.PL
@@ -22,7 +22,7 @@ print <<EOF;
 
 EOF
 
-do "constants.pl.PL"
+do "./constants.pl.PL"
    or die "cannot execute constants.pl.PL: $@";
 
 WriteMakefile(
