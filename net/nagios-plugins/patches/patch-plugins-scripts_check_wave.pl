$NetBSD: patch-plugins-scripts_check_wave.pl,v 1.1 2023/01/09 00:28:41 sekiya Exp $

Fix path to snmpget.

--- plugins-scripts/check_wave.pl.orig	2019-12-05 06:53:08.000000000 +0900
+++ plugins-scripts/check_wave.pl	2023-01-09 08:59:45.230098438 +0900
@@ -9,7 +9,7 @@
 use utils qw($TIMEOUT %ERRORS &print_revision &support);
 use vars qw($PROGNAME);
 use Getopt::Long;
-use vars qw($opt_V $opt_h $verbose $opt_w $opt_c $opt_H);
+use vars qw($opt_V $opt_h $verbose $opt_w $opt_c $opt_H $opt_C);
 my (@test, $low1, $med1, $high1, $snr, $low2, $med2, $high2);
 my ($low, $med, $high, $lowavg, $medavg, $highavg, $tot, $ss);
 
@@ -29,7 +29,8 @@
 	 "v" => \$verbose, "verbose"  => \$verbose,
 	 "w=s" => \$opt_w, "warning=s"  => \$opt_w,
 	 "c=s" => \$opt_c, "critical=s" => \$opt_c,
-	 "H=s" => \$opt_H, "hostname=s" => \$opt_H);
+	 "H=s" => \$opt_H, "hostname=s" => \$opt_H,
+	 "C=s" => \$opt_C, "community=s" => \$opt_C);
 
 if ($opt_V) {
 	print_revision($PROGNAME,'@NP_VERSION@'); #'
@@ -42,6 +43,7 @@
 }
 
 $opt_H = shift unless ($opt_H);
+$opt_C = "public" unless ($opt_C);
 unless ($opt_H) { print_usage(); exit -1; }
 my $host = $1 if ($opt_H =~ m/^([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+|[a-zA-Z][-a-zA-Z0]+(\.[a-zA-Z][-a-zA-Z0]+)*)$/);
 unless ($host) { print_usage(); exit -1; }
@@ -52,7 +54,7 @@
 ($opt_w) || ($opt_w = shift) || ($opt_w = 60);
 my $warning = $1 if ($opt_w =~ /([0-9]+)/);
 
-$low1 = `snmpget $host public .1.3.6.1.4.1.74.2.21.1.2.1.8.1 2>/dev/null`;
+$low1 = `$utils::PATH_TO_SNMPGET -c $opt_C $host .1.3.6.1.4.1.74.2.21.1.2.1.8.1 2>/dev/null`;
 unless ($low1) {
 	print "UNKNOWN - Could not find the 'snmpget' command Please install\n";
 	print "the snmp commands (usually net-snmp) before using $PROGNAME\n";
@@ -61,30 +63,30 @@
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
 
@@ -115,7 +117,7 @@
 
 
 sub print_usage () {
-	print "Usage: $PROGNAME -H <host> [-w <warn>] [-c <crit>]\n";
+	print "Usage: $PROGNAME -H <host> [-C <community>] [-w <warn>] [-c <crit>]\n";
 }
 
 sub print_help () {
