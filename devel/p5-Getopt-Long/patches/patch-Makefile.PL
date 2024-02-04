$NetBSD: patch-Makefile.PL,v 1.3 2024/02/04 05:44:24 schmonz Exp $

newgetopt.pl does exist in p5-Perl4-CoreLibs. To co-exist
with that,

--- Makefile.PL.orig	2023-11-09 22:08:55.000000000 +0000
+++ Makefile.PL
@@ -94,7 +94,7 @@ WriteMakefile(
         ),
 
 	INSTALLDIRS => ($] < 5.011 ? 'perl' : 'site'),
-	PM 	  => { "lib/newgetopt.pl"   => '$(INST_LIB)/newgetopt.pl',
+	PM 	  => {
 		       "lib/Getopt/Long.pm" => '$(INST_LIB)/Getopt/Long.pm',
 		       "lib/Getopt/Long/Parser.pm" => '$(INST_LIB)/Getopt/Long/Parser.pm',
 		     },
