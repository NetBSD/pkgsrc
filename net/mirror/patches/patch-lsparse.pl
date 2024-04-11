$NetBSD: patch-lsparse.pl,v 1.1 2024/04/11 10:23:44 bouyer Exp $

* Fix deprecation warning (change ' to ::) for newer perl

--- lsparse.pl.orig	1998-05-29 21:04:23.000000000 +0200
+++ lsparse.pl	2024-04-11 11:07:48.800742520 +0200
@@ -14,7 +14,7 @@
 # This software is provided "as is" without express or implied warranty.
 #
 # Parse "ls -lR" type listings
-# use lsparse'reset( dirname ) repeately
+# use lsparse::reset( dirname ) repeately
 #
 # By Lee McLoughlin <lmjm@icparc.ic.ac.uk>
 #
@@ -61,18 +61,18 @@
 local( $match );
 
 # The filestore type being scanned
-$lsparse'fstype = 'unix';
+$lsparse::fstype = 'unix';
 
 # Keep whatever case is on the remote system.  Otherwise lowercase it.
-$lsparse'vms_keep_case = '';
+$lsparse::vms_keep_case = '';
 
 # A name to report when errors occur
-$lsparse'name = 'unknown';
+$lsparse::name = 'unknown';
 
 # Wether to report subdirs when finding them in a directory
 # or when their details appear.  (If you report early then mirro might
 # recreate locally remote restricted directories.)
-$lsparse'report_subdir = 0;	# Report when finding details.
+$lsparse::report_subdir = 0;	# Report when finding details.
 
 
 # Name of routine to call to parse incoming listing lines
@@ -81,7 +81,7 @@
 # Set the directory that is being scanned and
 # check that the scan routing for this fstype exists
 # returns false if the fstype is unknown.
-sub lsparse'reset
+sub lsparse::reset
 {
 	$here = $currdir = $_[0];
 	$now = time;
@@ -91,17 +91,17 @@
 	$vms_strip =~ s,^/+,,;
 	$vms_strip =~ s,/+$,,;
 
-	$ls_line = "lsparse'line_$fstype";
+	$ls_line = "lsparse::line_$fstype";
 	return( defined( &$ls_line ) );
 }
 
 # See line_unix following routine for call/return details.
 # This calls the filestore specific parser.
-sub lsparse'line
+sub lsparse::line
 {
 	local( $fh ) = @_;
 
-	# ls_line is setup in lsparse'reset to the name of the function
+	# ls_line is setup in lsparse::reset to the name of the function
 	local( $path, $size, $time, $type, $mode ) =
 		eval "&$ls_line( \$fh )";
 
@@ -119,7 +119,7 @@
 # time is a Un*x time value for the file
 # type is "f" for a file, "d" for a directory and
 #         "l linkname" for a symlink
-sub lsparse'line_unix
+sub lsparse::line_unix
 {
 	local( $fh ) = @_;
 	local( $non_crud, $perm_denied );
@@ -132,7 +132,7 @@
 
 	while( <$fh> ){
 		# Store listing
-		print main'STORE $_;
+		print main::STORE $_;
 
 		# Stomp on carriage returns
 		s/\015//g;
@@ -168,7 +168,7 @@
 		if( $perm_denied ){
 			$perm_denied = "";
 			warn "Warning: input corrupted by 'Permission denied'",
-				"errors, about line $. of $lsparse'name\n";
+				"errors, about line $. of $lsparse::name\n";
 			next;
 		}
 		# Not found's are like Permission denied's.  They can start part
@@ -180,7 +180,7 @@
 		if( $not_found ){
 			$not_found = "";
 			warn "Warning: input corrupted by 'not found' errors",
-				" about line $. of $lsparse'name\n";
+				" about line $. of $lsparse::name\n";
 			next;
 		}
 		
@@ -196,7 +196,7 @@
 				next;
 			}
 
-			local( $time ) = &main'lstime_to_time( $lsdate );
+			local( $time ) = &main::lstime_to_time( $lsdate );
 			local( $type ) = '?';
 			local( $mode ) = 0;
 
@@ -316,7 +316,7 @@
 # time is a Un*x time value for the file
 # type is "f" for a file, "d" for a directory and
 #         "l linkname" for a symlink
-sub lsparse'line_dls
+sub lsparse::line_dls
 {
 	local( $fh ) = @_;
 	local( $non_crud, $perm_denied );
@@ -327,7 +327,7 @@
 
 	while( <$fh> ){
 		# Store listing
-		print main'STORE $_;
+		print main::STORE $_;
 
 		# Stomp on carriage returns
 		s/\015//g;
@@ -350,7 +350,7 @@
 			}
 			else {
 				# a file
-				$time = &main'lstime_to_time( $lsdate );
+				$time = &main::lstime_to_time( $lsdate );
 				$type = 'f';
 				$mode = 0444;
 			}
@@ -400,7 +400,7 @@
 # time is a Un*x time value for the file
 # type is "f" for a file, "d" for a directory and
 #         "l linkname" for a symlink
-sub lsparse'line_netware
+sub lsparse::line_netware
 {
 	local( $fh ) = @_;
 
@@ -410,7 +410,7 @@
 
 	while( <$fh> ){
 		# Store listing
-		print main'STORE $_;
+		print main::STORE $_;
 
 		# Stomp on carriage returns
 		s/\015//g;
@@ -435,7 +435,7 @@
 			if( $file eq '.' || $file eq '..' ){
 				next;
 			}
-			local( $time ) = &main'lstime_to_time( $lsdate );
+			local( $time ) = &main::lstime_to_time( $lsdate );
 			local( $type ) = '?';
 			local( $mode ) = 0;
 
@@ -509,7 +509,7 @@
 # time is a Un*x time value for the file
 # type is "f" for a file, "d" for a directory and
 #         "l linkname" for a symlink
-sub lsparse'line_vms
+sub lsparse::line_vms
 {
 	local( $fh ) = @_;
 	local( $non_crud, $perm_denied );
@@ -520,7 +520,7 @@
 
 	while( <$fh> ){
 		# Store listing
-		print main'STORE $_;
+		print main::STORE $_;
 
 		# Stomp on carriage returns
 		s/\015//g;
@@ -543,7 +543,7 @@
 		}
 
 		# Upper case is so ugly
-		if( ! $lsparse'vms_keep_case ){
+		if( ! $lsparse::vms_keep_case ){
 			tr/A-Z/a-z/;
 		}
 
@@ -584,7 +584,7 @@
 		$size = 0;
 		
 		if( $got ){
-			local( $time ) = &main'lstime_to_time( $lsdate );
+			local( $time ) = &main::lstime_to_time( $lsdate );
 			local( $type ) = 'f';
 			local( $mode ) = 0444;
 
@@ -610,7 +610,7 @@
 				$mode = 0555;
 			}
 
-			$lsparse'vers = $vers;
+			$lsparse::vers = $vers;
 
 #print "file=|$file| match=|$match| vms_strip=|$vms_strip|\n";
 			$file =~ s,^,/,;
@@ -653,7 +653,7 @@
 # time is a Un*x time value for the file
 # type is "f" for a file, "d" for a directory and
 #         "l linkname" for a symlink
-sub lsparse'line_dosftp
+sub lsparse::line_dosftp
 {
 	local( $fh ) = @_;
 
@@ -670,7 +670,7 @@
 			$_ = <$fh>;
 
 			# Store listing
-			print main'STORE $_;
+			print main::STORE $_;
 
 			# Ignore the summary at the end and blank lines
 			if( /^\d+ files?\./ || /^\s+$/ ){
@@ -691,7 +691,7 @@
 
 			# TODO: fix hacky 19$yr
 			local( $lsdate ) = "$day-$mon-19$yr $hrs:$min";
-			local( $time ) = &main'lstime_to_time( $lsdate );
+			local( $time ) = &main::lstime_to_time( $lsdate );
 			local( $type ) = '?';
 			local( $mode ) = 0;
 
@@ -736,7 +736,7 @@
 # 03-08-94  07:17AM                 5504 article.xfiles.intro
 # 02-28-94  11:44AM                 3262 article1.gillian.anderson
 
-sub lsparse'line_dosish
+sub lsparse::line_dosish
 {
 	local( $fh ) = @_;
 
@@ -748,7 +748,7 @@
 		$_ = <$fh>;
 
 		# Store listing
-		print main'STORE $_;
+		print main::STORE $_;
 
 		# Ignore blank lines
 		if( /^\s+$/ ){
@@ -775,7 +775,7 @@
 
 			# TODO: fix hacky 19$yr
 			local( $lsdate ) = "$day-$mon-19$yr $hrs:$min";
-			local( $time ) = &main'lstime_to_time( $lsdate );
+			local( $time ) = &main::lstime_to_time( $lsdate );
 			local( $type ) = ($dir_or_size eq '<DIR>' ? 'd' : 'f');
 			local( $mode ) = 0;
 			local( $size ) = 0;
@@ -842,7 +842,7 @@
 # WPKIT1.EXE          960338      06/21/95        17:01
 # CMT.CSV                  0      07/06/95        14:56
 
-sub lsparse'line_supertcp
+sub lsparse::line_supertcp
 {
     local( $fh ) = @_;
 
@@ -860,7 +860,7 @@
 	    $_ = <$fh>;
 
 	    # Store listing
-	    print main'STORE $_;
+	    print main::STORE $_;
 
 	    # Ignore the summary at the end and blank lines
 	    if( /^\d+ files?\./ || /^\s+$/ ){
@@ -885,7 +885,7 @@
 	    $pending = $5;
 
 	    local( $lsdate ) = "$day-$mon-$yr $time";
-	    local( $time ) = &main'lstime_to_time( $lsdate );
+	    local( $time ) = &main::lstime_to_time( $lsdate );
             local( $type ) = '?';
 	    local( $mode ) = 0;
 
@@ -931,7 +931,7 @@
 #               372      A          08-09-95   10:26  Aussie_1.bag
 #            310992                 06-28-94   09:56  INSTALL.EXE
 
-sub lsparse'line_os2
+sub lsparse::line_os2
 {
 	local( $fh ) = @_;
 
@@ -943,7 +943,7 @@
 		$_ = <$fh>;
 
 		# Store listing
-		print main'STORE $_;
+		print main::STORE $_;
 
 		# Ignore blank lines
 		if( /^\s+$/ ){
@@ -971,7 +971,7 @@
 
 			# TODO: fix hacky 19$yr
 			local( $lsdate ) = "$day-$mon-19$yr $hrs:$min";
-			local( $time ) = &main'lstime_to_time( $lsdate );
+			local( $time ) = &main::lstime_to_time( $lsdate );
 			local( $type ) = ($dir eq 'DIR' ? 'd' : 'f');
 			local( $mode ) = 0;
 
@@ -999,7 +999,7 @@
 # time is a Un*x time value for the file
 # type is "f" for a file, "d" for a directory and
 #         "l linkname" for a symlink
-sub lsparse'line_chameleon
+sub lsparse::line_chameleon
 {
     local( $fh ) = @_;
 
@@ -1038,7 +1038,7 @@
 	    $pending = $5;
 
 	    local( $lsdate ) = "$day-$mon-$yr $time";
-	    local( $time ) = &main'lstime_to_time( $lsdate );
+	    local( $time ) = &main::lstime_to_time( $lsdate );
             local( $type ) = '?';
 	    local( $mode ) = 0;
 
@@ -1076,7 +1076,7 @@
 # time is a Un*x time value for the file
 # type is "f" for a file, "d" for a directory and
 #         "l linkname" for a symlink
-sub lsparse'line_macos
+sub lsparse::line_macos
 {
 	local( $fh ) = @_;
 	local( $non_crud, $perm_denied );
@@ -1087,7 +1087,7 @@
 
 	while( <$fh> ){
 		# Store listing
-		print main'STORE $_;
+		print main::STORE $_;
 
 		# Stomp on carriage returns
 		s/\015//g;
@@ -1098,7 +1098,7 @@
 		if( /^([\-rwxd]{10}).*\s(\d+\s+)?(\S+)\s+\d+\s*(\w\w\w\s+\d+\s*(\d+:\d+|\d\d\d\d))\s+(.*)\n/ ){
 			local( $kind, $size, $lsdate, $file ) = ($1, $3, $4, $6);
 			
-			local( $time ) = &main'lstime_to_time( $lsdate );
+			local( $time ) = &main::lstime_to_time( $lsdate );
 			local( $type ) = '?';
 			local( $mode ) = 0;
 
@@ -1126,18 +1126,18 @@
 
 
 # --------------------- parse lsparse log file format
-# lsparse'line_lsparse() is for input in lsparse's internal form,
+# lsparse::line_lsparse() is for input in lsparse's internal form,
 # as it might have been written to a log file during a previous
 # run of a program that uses lsparse.  The format is:
 #     filename size time type mode
 # where size and time are in decimal, mode is in decimal or octal,
 # and type is one or two words.
-sub lsparse'line_lsparse
+sub lsparse::line_lsparse
 {
 	local( $fh ) = @_;
 
-	if( $lsparse'readtime ){
-		alarm( $lsparse'readtime );
+	if( $lsparse::readtime ){
+		alarm( $lsparse::readtime );
 	}
 
 	if( eof( $fh ) ){
@@ -1147,7 +1147,7 @@
 
 	while( <$fh> ){
 		# Store listing
-		print main'STORE $_;
+		print main::STORE $_;
 
 		if( /^(\S+)\s+(\d+)\s+(\d+)\s+((l\s+)?\S+)\s+(\d+)\n$/ ){
 			# looks good.
@@ -1174,12 +1174,12 @@
 # This is the format used at sumex-aim.stanford.edu for the info-mac area.
 # (see info-mac/help/all-files.txt.gz).
 #
-sub lsparse'line_infomac
+sub lsparse::line_infomac
 {
 	local( $fh ) = @_;
 
-	if( $lsparse'readtime ){
-		alarm( $lsparse'readtime );
+	if( $lsparse::readtime ){
+		alarm( $lsparse::readtime );
 	}
 
 	if( eof( $fh ) ){
@@ -1189,13 +1189,13 @@
 
 	while( <$fh> ){
 		# Store listing
-		print main'STORE $_;
+		print main::STORE $_;
 
 		next if /^;/;
 		if( /^([l-].)\s*(\d+)\s*(\w\w\w\s+\d+\s*(\d+:\d+|\d\d\d\d))\s+(.*)\n/ ){
 			local( $kind, $size, $lsdate, $file ) = ($1, $2, $3, $5);
 			
-			local( $time ) = &main'lstime_to_time( $lsdate );
+			local( $time ) = &main::lstime_to_time( $lsdate );
 
 			# This should be a symlink
 			if( $kind =~ /^l/ && $file =~ /(.*) -> (.*)/ ){
@@ -1226,12 +1226,12 @@
 # +i8388621.48638,m848117771,r,s1336,     qmsmac.html
 # +i8388621.88705,m850544954,/,   txt
 #
-sub lsparse'line_eplf
+sub lsparse::line_eplf
 {
 	local( $fh ) = @_;
 
-	if( $lsparse'readtime ){
-		alarm( $lsparse'readtime );
+	if( $lsparse::readtime ){
+		alarm( $lsparse::readtime );
 	}
 
 	if( eof( $fh ) ){
@@ -1243,7 +1243,7 @@
 		s/\015//g;
 
 		# Store listing
-		print main'STORE $_;
+		print main::STORE $_;
 
 # +i8388621.48638,m848117771,r,s1336,     qmsmac.html
 # +i8388621.88705,m850544954,/,   txt
@@ -1272,12 +1272,12 @@
 # --------------------- CTAN files list
 #    22670 Mon Jul 20 12:36:34 1992 pub/tex/biblio/bibtex/contrib/aaai-named.bst
 #
-sub lsparse'line_ctan
+sub lsparse::line_ctan
 {
 	local( $fh ) = @_;
 
-	if( $lsparse'readtime ){
-		alarm( $lsparse'readtime );
+	if( $lsparse::readtime ){
+		alarm( $lsparse::readtime );
 	}
 
 	if( eof( $fh ) ){
@@ -1287,12 +1287,12 @@
 
 	while( <$fh> ){
 		# Store listing
-		print main'STORE $_;
+		print main::STORE $_;
 
 		if( /^\s*(\d+)\s+(\w\w\w\s+\w\w\w\s+\d+\s+\d+:\d+:\d+\s+\d+)\s+(.*)\n/ ){
 			local( $size, $lsdate, $file ) = ($1, $2, $3);
 			
-			local( $time ) = &main'lstime_to_time( $lsdate );
+			local( $time ) = &main::lstime_to_time( $lsdate );
 
 			return( $file, $size, $time, 'f', 0444 );
 		}
@@ -1317,12 +1317,12 @@
 # time is a Un*x time value for the file -- this is good from the m/f
 # type is always "f" for a file
 
-sub lsparse'line_cms
+sub lsparse::line_cms
 {
 	local( $fh ) = @_;
 
-	if( $lsparse'readtime ){
-		alarm( $lsparse'readtime );
+	if( $lsparse::readtime ){
+		alarm( $lsparse::readtime );
 	}
 
 	if( eof( $fh ) ){
@@ -1331,21 +1331,21 @@
 	}
 	while( <$fh> ){
 		# Store listing
-		print main'STORE $_;
+		print main::STORE $_;
 
 		chop;
 		next unless /\d+\/\d+\/\d+\s+\d+:\d+:\d+/;
 		s/^\s+//;
 
 		# Upper case is so ugly
-		if( ! $lsparse'vms_keep_case ){
+		if( ! $lsparse::vms_keep_case ){
 			tr/A-Z/a-z/;
 		}
 
 		local( $fname, $ftype, $fdisk, $rectype, $lrecl, $recs,
 		      $blocks, $ldate, $tod ) = split(/\s+/, $_);
 		return( join('.', ($fname, $ftype, $fdisk)),
-		       $lrecl * $recs, &main'lstime_to_time( "$ldate $tod" ),
+		       $lrecl * $recs, &main::lstime_to_time( "$ldate $tod" ),
 		       'f' );
 	}
 	alarm( 0 );
