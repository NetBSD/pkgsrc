$NetBSD: patch-lib_mhopt.pl,v 1.3.2.2 2015/10/02 19:49:13 bsiegert Exp $

perl 5.22 compatipility

--- lib/mhopt.pl.orig	2015-09-26 12:35:06.000000000 +0200
+++ lib/mhopt.pl	2015-09-26 12:35:18.000000000 +0200
@@ -865,7 +865,7 @@
 sub update_data_2_1_to_later {
     no warnings qw(deprecated);
     # we can preserve filter arguments
-    if (defined(%main::MIMEFiltersArgs)) {
+    if (%main::MIMEFiltersArgs) {
 	warn qq/         preserving MIMEARGS...\n/;
 	%readmail::MIMEFiltersArgs = %main::MIMEFiltersArgs;
 	$IsDefault{'MIMEARGS'} = 0;
