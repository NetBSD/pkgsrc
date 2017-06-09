$NetBSD: patch-Makefile.PL,v 1.1 2017/06/09 16:55:10 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2016-09-23 19:40:12.000000000 +0000
+++ Makefile.PL
@@ -153,7 +153,7 @@ print F qq|#define NI_OSVER_BASE $Config
 close F;
 
 ################ build family definitions
-do 'inst/netsymbols.pl';
+do './inst/netsymbols.pl';
 ## END ######### build family definitions
 
 sub MY::top_targets {
