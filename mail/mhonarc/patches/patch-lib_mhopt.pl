$NetBSD: patch-lib_mhopt.pl,v 1.1 2011/10/30 22:03:42 spz Exp $

--- lib/mhopt.pl.orig	2011-01-09 05:13:14.000000000 +0000
+++ lib/mhopt.pl
@@ -864,7 +864,7 @@ sub update_data_1_to_2 {
 ##
 sub update_data_2_1_to_later {
     # we can preserve filter arguments
-    if (defined(%main::MIMEFiltersArgs)) {
+    if (%main::MIMEFiltersArgs) {
 	warn qq/         preserving MIMEARGS...\n/;
 	%readmail::MIMEFiltersArgs = %main::MIMEFiltersArgs;
 	$IsDefault{'MIMEARGS'} = 0;
