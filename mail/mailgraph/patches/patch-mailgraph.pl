$NetBSD: patch-mailgraph.pl,v 1.1 2019/10/02 14:30:31 triaxx Exp $

* Use log/maillog as default mail logfile.
* Change hardcoded /var to pkgsrc compliant VARBASE.

--- mailgraph.pl.orig	2007-08-29 09:06:01.000000000 +0000
+++ mailgraph.pl
@@ -371,9 +371,9 @@ my $rrdstep = 60;
 my $xpoints = 540;
 my $points_per_sample = 3;
 
-my $daemon_logfile = '/var/log/mailgraph.log';
-my $daemon_pidfile = '/var/run/mailgraph.pid';
-my $daemon_rrd_dir = '/var/log';
+my $daemon_logfile = '@VARBASE@/log/mailgraph.log';
+my $daemon_pidfile = '@VARBASE@/run/mailgraph.pid';
+my $daemon_rrd_dir = '@VARBASE@/db/mailgraph';
 
 # global variables
 my $logfile;
@@ -405,14 +405,14 @@ sub usage
 	print "  -v, --verbose      be verbose about what you do\n";
 	print "  -V, --version      output version information and exit\n";
 	print "  -c, --cat          causes the logfile to be only read and not monitored\n";
-	print "  -l, --logfile f    monitor logfile f instead of /var/log/syslog\n";
+	print "  -l, --logfile f    monitor logfile f instead of @VARBASE@/log/maillog\n";
 	print "  -t, --logtype t    set logfile's type (default: syslog)\n";
 	print "  -y, --year         starting year of the log file (default: current year)\n";
 	print "      --host=HOST    use only entries for HOST (regexp) in syslog\n";
 	print "  -d, --daemon       start in the background\n";
-	print "  --daemon-pid=FILE  write PID to FILE instead of /var/run/mailgraph.pid\n";
-	print "  --daemon-rrd=DIR   write RRDs to DIR instead of /var/log\n";
-	print "  --daemon-log=FILE  write verbose-log to FILE instead of /var/log/mailgraph.log\n";
+	print "  --daemon-pid=FILE  write PID to FILE instead of @VARBASE@/run/mailgraph.pid\n";
+	print "  --daemon-rrd=DIR   write RRDs to DIR instead of @VARBASE@/log\n";
+	print "  --daemon-log=FILE  write verbose-log to FILE instead of @VARBASE@/log/mailgraph.log\n";
 	print "  --ignore-localhost ignore mail to/from localhost (used for virus scanner)\n";
 	print "  --ignore-host=HOST ignore mail to/from HOST regexp (used for virus scanner)\n";
 	print "  --only-mail-rrd    update only the mail rrd\n";
@@ -461,7 +461,7 @@ sub main
 
 	daemonize if $opt{daemon};
 
-	my $logfile = defined $opt{logfile} ? $opt{logfile} : '/var/log/syslog';
+	my $logfile = defined $opt{logfile} ? $opt{logfile} : '@VARBASE@/log/maillog';
 	my $file;
 	if($opt{cat}) {
 		$file = $logfile;
@@ -909,14 +909,14 @@ B<mailgraph> [I<options>...]
  -v, --verbose      be verbose about what you do
  -V, --version      output version information and exit
  -c, --cat          causes the logfile to be only read and not monitored
- -l, --logfile f    monitor logfile f instead of /var/log/syslog
+ -l, --logfile f    monitor logfile f instead of @VARBASE@/log/maillog
  -t, --logtype t    set logfile's type (default: syslog)
  -y, --year         starting year of the log file (default: current year)
      --host=HOST    use only entries for HOST (regexp) in syslog
  -d, --daemon       start in the background
- --daemon-pid=FILE  write PID to FILE instead of /var/run/mailgraph.pid
- --daemon-rrd=DIR   write RRDs to DIR instead of /var/log
- --daemon-log=FILE  write verbose-log to FILE instead of /var/log/mailgraph.log
+ --daemon-pid=FILE  write PID to FILE instead of @VARBASE@/run/mailgraph.pid
+ --daemon-rrd=DIR   write RRDs to DIR instead of @VARBASE@/log
+ --daemon-log=FILE  write verbose-log to FILE instead of @VARBASE@/log/mailgraph.log
  --ignore-localhost ignore mail to/from localhost (used for virus scanner)
  --ignore-host=HOST ignore mail to/from HOST regexp (used for virus scanner)
  --only-mail-rrd    update only the mail rrd
