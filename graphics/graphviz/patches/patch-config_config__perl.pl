$NetBSD: patch-config_config__perl.pl,v 1.4 2022/07/22 12:04:46 micha Exp $

Add rpath for pkgsrc

--- config/config_perl.pl.orig	2013-08-01 17:35:15.000000000 +0000
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
