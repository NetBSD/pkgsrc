$NetBSD: patch-plugins-scripts_check_breeze.pl,v 1.1 2023/01/09 00:28:41 sekiya Exp $

Fix path to snmpget.

--- plugins-scripts/check_breeze.pl.orig	2017-01-17 02:24:03.000000000 +0900
+++ plugins-scripts/check_breeze.pl	2023-01-09 08:51:25.244526777 +0900
@@ -49,7 +49,7 @@
 ($opt_C) || ($opt_C = "public") ;
 
 my $sig=0;
-$sig = `/usr/bin/snmpget $host $opt_C .1.3.6.1.4.1.710.3.2.3.1.3.0`;
+$sig = `$utils::PATH_TO_SNMPGET -c $opt_C $host .1.3.6.1.4.1.710.3.2.3.1.3.0`;
 my @test=split(/ /,$sig);
 $sig=$test[2];
 $sig=int($sig);
