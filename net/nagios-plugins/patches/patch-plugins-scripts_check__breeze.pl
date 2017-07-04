$NetBSD: patch-plugins-scripts_check__breeze.pl,v 1.1 2017/07/04 19:45:18 jperkin Exp $

Fix path to snmpget.

--- plugins-scripts/check_breeze.pl.orig	2017-01-16 17:24:03.000000000 +0000
+++ plugins-scripts/check_breeze.pl
@@ -49,7 +49,7 @@ my $critical = $1 if ($opt_c =~ /([0-9]{
 ($opt_C) || ($opt_C = "public") ;
 
 my $sig=0;
-$sig = `/usr/bin/snmpget $host $opt_C .1.3.6.1.4.1.710.3.2.3.1.3.0`;
+$sig = `$utils::PATH_TO_SNMPGET -c $opt_C $host .1.3.6.1.4.1.710.3.2.3.1.3.0`;
 my @test=split(/ /,$sig);
 $sig=$test[2];
 $sig=int($sig);
