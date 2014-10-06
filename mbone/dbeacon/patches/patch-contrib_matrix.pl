$NetBSD: patch-contrib_matrix.pl,v 1.1 2014/10/06 10:04:17 he Exp $

Fix syntax errors flagged by newer perl.
Fix flag pointer, ref.
https://lists.ubuntu.com/archives/ubuntu-motu/2010-January/006495.html

--- contrib/matrix.pl.orig	2013-07-05 19:12:49.000000000 +0200
+++ contrib/matrix.pl	2014-10-06 11:46:41.000000000 +0200
@@ -29,7 +29,7 @@
 our $css_file;
 our $dump_update_delay = 5;	# time between each normal dumps
 				# (used to detect outdated dump files)
-our $flag_url_format = 'http://www.sixxs.net/gfx/countries/%s.gif';
+our $flag_url_format = 'http://www.sixxs.net/s/countries/%s.gif';
 our $default_ssm_group = 'ff3e::beac/10000';
 our $debug = 0;
 our $matrix_link_title = 0;
@@ -423,7 +423,7 @@
 			$adj{$current_beacon}[RX_LOCAL] = $atts{'rxlocal'} if defined $atts{'rxlocal'};
 		}
 	} elsif ($tag eq 'asm' or $tag eq 'ssm') {
-		foreach my $att qw(ttl loss delay jitter) {
+		foreach my $att (qw(ttl loss delay jitter)) {
 			if (defined $atts{$att}) {
 				my $index = $tag eq 'ssm' ? 2 : 1;
 
@@ -884,7 +884,10 @@
 				}
 			} elsif ($a eq $b) {
 				printx '<td ', $what_td, ' class="corner">&nbsp;</td>';
-			} elsif ($full_matrix and $adj{$a}[RX_LOCAL] ne 'true') {
+			} elsif ($full_matrix and
+				 defined($adj{$a}[RX_LOCAL]) and
+				 $adj{$a}[RX_LOCAL] ne 'true')
+			{
 				printx '<td ', $what_td, ' class="noreport">N/R</td>';
 			} else {
 				printx '<td ', $what_td, ' class="blackhole">XX</td>';
@@ -1171,7 +1174,7 @@
 	update_ttl_hist(build_history_file_path($dst_h, $src_h) . "/$tag-ttl-hist",
 		$adj{$dst}[NEIGH]{$src}[$index]{'ttl'}) if defined $adj{$dst}[NEIGH]{$src}[$index]{'ttl'};
 
-	foreach my $type qw(ttl loss delay jitter) {
+	foreach my $type (qw(ttl loss delay jitter)) {
 		$values{$type} = $adj{$dst}[NEIGH]{$src}[$index]{$type};
 		$good++ if defined $values{$type};
 	}
@@ -1263,7 +1266,7 @@
 	# Update rrd with new values
 
 	my $updatestring = 'N';
-	foreach my $valuetype qw(ttl loss delay jitter) {
+	foreach my $valuetype (qw(ttl loss delay jitter)) {
 		# Store it in s and not ms
 		$values{$valuetype} = $values{$valuetype} / 1000. if $valuetype eq 'delay' or $valuetype eq 'jitter';
 		$updatestring .= ':' . $values{$valuetype};
@@ -1644,7 +1647,7 @@
 
 		my $count = 0;
 
-		foreach my $type qw(ttl loss delay jitter) {
+		foreach my $type (qw(ttl loss delay jitter)) {
 			printx '<tr>' if ($count % 2) == 0;
 			printx '<td>';
 			graphthumb($type);
