$NetBSD: patch-mailgraph.cgi,v 1.1 2019/10/02 14:30:31 triaxx Exp $

* Change relative path of rrd files to absolute path (maildgraph must be run as
  daemon).
* Change hardcoded /var to pkgsrc compliant VARBASE.

--- mailgraph.cgi.orig	2007-08-29 09:06:01.000000000 +0000
+++ mailgraph.cgi
@@ -16,8 +16,8 @@ my $xpoints = 540;
 my $points_per_sample = 3;
 my $ypoints = 160;
 my $ypoints_err = 96;
-my $rrd = 'mailgraph.rrd'; # path to where the RRD database is
-my $rrd_virus = 'mailgraph_virus.rrd'; # path to where the Virus RRD database is
+my $rrd = '@VARBASE@/db/mailgraph/mailgraph.rrd'; # path to where the RRD database is
+my $rrd_virus = '@VARBASE@/db/mailgraph/mailgraph_virus.rrd'; # path to where the Virus RRD database is
 my $tmp_dir = '/tmp/mailgraph'; # temporary directory where to store the images
 
 my @graphs = (
