$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:56:57 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2013-04-10 14:04:00.000000000 +0000
+++ Makefile.PL
@@ -2,4 +2,6 @@
 # Copyright 2001 Abhijit Menon-Sen <ams@wiw.org>
 
+use FindBin;
+use lib $FindBin::Bin;
 use Config;
 use File::Spec;
@@ -50,5 +52,5 @@ print F $text;
 close F;
 
-sub MY::postamble { "tables.h: tab/tables.pl\n\t\$(PERL) tab/tables.pl\n" }
+sub MY::postamble { "tables.h: tab/tables.pl\n\tPERL5LIB=. \$(PERL) tab/tables.pl\n" }
 
 WriteMakefile(
