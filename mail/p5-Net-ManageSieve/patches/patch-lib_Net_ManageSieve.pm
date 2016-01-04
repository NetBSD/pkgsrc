$NetBSD: patch-lib_Net_ManageSieve.pm,v 1.1 2016/01/04 02:20:45 markd Exp $

Unescaped braces in regexp are deprecated and issue a warning
when used in Perl 5.22.
--- lib/Net/ManageSieve.pm.orig	2012-01-12 15:35:27.000000000 +0000
+++ lib/Net/ManageSieve.pm
@@ -1034,7 +1034,7 @@ sub _token {
 		$l =~ s/\A[[:blank:]]+//;
 	}
 
-	if($l =~ /\A{(\d+)\+?}\r*\Z/) {	# The next $1 octets are the token
+	if($l =~ /\A\{(\d+)\+?\}\r*\Z/) {	# The next $1 octets are the token
 		my $cnt = $1;
 		$l = '';
 		while($cnt > 0) {	# Need some characters still
