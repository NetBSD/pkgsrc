$NetBSD: patch-Makefile.PL,v 1.1 2016/05/06 12:41:59 mef Exp $

newgetopt.pl does exist in p5-Perl4-CoreLibs. To co-exist
with that,

--- Makefile.PL.orig	2013-07-08 15:14:42.000000000 +0900
+++ Makefile.PL	2016-04-25 22:02:20.000000000 +0900
@@ -89,7 +89,7 @@ WriteMakefile(
         ),
 
 	INSTALLDIRS => ($] < 5.011 ? 'perl' : 'site'),
-	PM 	  => { "lib/newgetopt.pl"  => '$(INST_LIB)/newgetopt.pl',
+	PM 	  => { 
 		       "lib/Getopt/Long.pm" => '$(INST_LIB)/Getopt/Long.pm',
 		     },
 	dist      => { COMPRESS => 'gzip', SUFFIX => 'gz',
