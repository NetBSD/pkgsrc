$NetBSD: patch-plugins-scripts_check__wave.pl,v 1.1 2017/07/04 19:45:18 jperkin Exp $

Fix path to snmpget.

--- plugins-scripts/check_wave.pl.orig	2017-01-16 17:24:03.000000000 +0000
+++ plugins-scripts/check_wave.pl
@@ -9,7 +9,7 @@ use lib '@libexecdir@';
 use utils qw($TIMEOUT %ERRORS &print_revision &support);
 use vars qw($PROGNAME);
 use Getopt::Long;
-use vars qw($opt_V $opt_h $verbose $opt_w $opt_c $opt_H);
+use vars qw($opt_V $opt_h $verbose $opt_w $opt_c $opt_H $opt_C);
 my (@test, $low1, $med1, $high1, $snr, $low2, $med2, $high2);
 my ($low, $med, $high, $lowavg, $medavg, $highavg, $tot, $ss);
 
@@ -28,7 +28,8 @@ GetOptions
 	 "v" => \$verbose, "verbose"  => \$verbose,
 	 "w=s" => \$opt_w, "warning=s"  => \$opt_w,
 	 "c=s" => \$opt_c, "critical=s" => \$opt_c,
-	 "H=s" => \$opt_H, "hostname=s" => \$opt_H);
+	 "H=s" => \$opt_H, "hostname=s" => \$opt_H,
+	 "C=s" => \$opt_C, "community=s" => \$opt_C);
 
 if ($opt_V) {
 	print_revision($PROGNAME,'@NP_VERSION@'); #'
@@ -41,6 +42,7 @@ if ($opt_h) {
 }
 
 $opt_H = shift unless ($opt_H);
+$opt_C = "public" unless ($opt_C);
 print_usage() unless ($opt_H);
 my $host = $1 if ($opt_H =~ m/^([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+|[a-zA-Z][-a-zA-Z0]+(\.[a-zA-Z][-a-zA-Z0]+)*)$/);
 print_usage() unless ($host);
@@ -51,34 +53,34 @@ my $critical = $1 if ($opt_c =~ /([0-9]+
 ($opt_w) || ($opt_w = shift) || ($opt_w = 60);
 my $warning = $1 if ($opt_w =~ /([0-9]+)/);
 
-$low1 = `snmpget $host public .1.3.6.1.4.1.74.2.21.1.2.1.8.1`;
+$low1 = `$utils::PATH_TO_SNMPGET -c $opt_C $host .1.3.6.1.4.1.74.2.21.1.2.1.8.1`;
 @test = split(/ /,$low1);
 $low1 = $test[2];
 
-$med1 = `snmpget $host public .1.3.6.1.4.1.74.2.21.1.2.1.9.1`;
+$med1 = `$utils::PATH_TO_SNMPGET -c $opt_C $host .1.3.6.1.4.1.74.2.21.1.2.1.9.1`;
 @test = split(/ /,$med1);
 $med1 = $test[2];
 
-$high1 = `snmpget $host public .1.3.6.1.4.1.74.2.21.1.2.1.10.1`;
+$high1 = `$utils::PATH_TO_SNMPGET -c $opt_C $host .1.3.6.1.4.1.74.2.21.1.2.1.10.1`;
 @test = split(/ /,$high1);
 $high1 = $test[2];
 
 sleep(2);
 
-$snr = `snmpget $host public .1.3.6.1.4.1.762.2.5.2.1.17.1`;
+$snr = `$utils::PATH_TO_SNMPGET -c $opt_C $host .1.3.6.1.4.1.762.2.5.2.1.17.1`;
 @test = split(/ /,$snr);
 $snr = $test[2];
 $snr = int($snr*25);
 
-$low2 = `snmpget $host public .1.3.6.1.4.1.74.2.21.1.2.1.8.1`;
+$low2 = `$utils::PATH_TO_SNMPGET -c $opt_C $host .1.3.6.1.4.1.74.2.21.1.2.1.8.1`;
 @test = split(/ /,$low2);
 $low2 = $test[2];
 
-$med2 = `snmpget $host public .1.3.6.1.4.1.74.2.21.1.2.1.9.1`;
+$med2 = `$utils::PATH_TO_SNMPGET -c $opt_C $host .1.3.6.1.4.1.74.2.21.1.2.1.9.1`;
 @test = split(/ /,$med2);
 $med2 = $test[2];
 
-$high2 = `snmpget $host public .1.3.6.1.4.1.74.2.21.1.2.1.10.1`;
+$high2 = `$utils::PATH_TO_SNMPGET -c $opt_C $host .1.3.6.1.4.1.74.2.21.1.2.1.10.1`;
 @test = split(/ /,$high2);
 $high2 = $test[2];
 
@@ -109,7 +111,7 @@ if ($ss<$critical) {
 
 
 sub print_usage () {
-	print "Usage: $PROGNAME -H <host> [-w <warn>] [-c <crit>]\n";
+	print "Usage: $PROGNAME -H <host> [-C <community>] [-w <warn>] [-c <crit>]\n";
 }
 
 sub print_help () {
