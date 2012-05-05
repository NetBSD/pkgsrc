$NetBSD: patch-cofig_config__perl.pl,v 1.1 2012/05/05 22:14:39 joerg Exp $

--- config/config_perl.pl.orig	2012-05-05 16:30:45.000000000 +0000
+++ config/config_perl.pl
@@ -4,7 +4,7 @@ if ($ARGV[0] eq "PERL_LIBS") {
 	$archlib = $Config{archlib};
 	$libperl = $Config{libperl};
 	$libperl =~ s/lib([^\.]+).*/$1/;
-	print "-L$archlib/CORE -l$libperl";
+	print "-Wl,-rpath,$archlib/CORE -L$archlib/CORE -l$libperl";
 }
 if ($ARGV[0] eq "PERL_INCLUDES") {
 	$archlib = $Config{archlib};
