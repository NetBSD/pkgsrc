$NetBSD: patch-contrib_scripts_vmail.cgi,v 1.1.1.1 2016/10/25 08:17:05 jnemeth Exp $

--- contrib/scripts/vmail.cgi.orig	2015-10-09 21:48:48.000000000 +0000
+++ contrib/scripts/vmail.cgi
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!/usr/pkg/bin/perl
 #
 # Web based Voicemail for Asterisk
 #
@@ -145,7 +145,7 @@ sub check_login($$)
 		$context = "default";
 	}
 	if (!$filename) {
-		$filename = "/etc/asterisk/voicemail.conf";
+		$filename = "@ASTETCDIR@/voicemail.conf";
 	}
 #	print header;
 #	print "Including <h2>$filename</h2> while in <h2>$category</h2>...\n";
@@ -153,7 +153,7 @@ sub check_login($$)
 	while(<VMAIL>) {
 		chomp;
 		if (/include\s\"([^\"]+)\"$/) {
-			($tmp, $category) = &check_login("/etc/asterisk/$1", $category);
+			($tmp, $category) = &check_login("@ASTETCDIR@/$1", $category);
 			if (length($tmp)) {
 #				print "Got '$tmp'\n";
 				return ($tmp, $category);
@@ -200,7 +200,7 @@ sub check_login_users {
 	my ($mbox, $context) = split(/\@/, param('mailbox'));
 	my $pass = param('password');
 	my ($found, $fullname) = (0, "");
-	open VMAIL, "</etc/asterisk/users.conf";
+	open VMAIL, "<@ASTETCDIR@/users.conf";
 	while (<VMAIL>) {
 		chomp;
 		if (m/\[(.*)\]/) {
@@ -242,7 +242,7 @@ sub validmailbox($$$$)
 		$context = "default";
 	}
 	if (!$filename) {
-		$filename = "/etc/asterisk/voicemail.conf";
+		$filename = "@ASTETCDIR@/voicemail.conf";
 	}
 	if (!$category) {
 		$category = "general";
@@ -251,7 +251,7 @@ sub validmailbox($$$$)
 	while (<VMAIL>) {
 		chomp;
 		if (/include\s\"([^\"]+)\"$/) {
-			($tmp, $category) = &validmailbox($mbox, $context, "/etc/asterisk/$1");
+			($tmp, $category) = &validmailbox($mbox, $context, "@ASTETCDIR@/$1");
 			if ($tmp) {
 				return ($tmp, $category);
 			}
@@ -298,7 +298,7 @@ sub mailbox_options()
 	local $tmp2;
 	local $tmp;
 	if (!$filename) {
-		$filename = "/etc/asterisk/voicemail.conf";
+		$filename = "@ASTETCDIR@/voicemail.conf";
 	}
 	if (!$category) {
 		$category = "general";
@@ -386,7 +386,7 @@ sub mailbox_list()
 sub msgcount() 
 {
 	my ($context, $mailbox, $folder) = @_;
-	my $path = "/var/spool/asterisk/voicemail/$context/$mailbox/$folder";
+	my $path = "@ASTSPOOLDIR@/voicemail/$context/$mailbox/$folder";
 	if (opendir(DIR, $path)) {
 		my @msgs = grep(/^msg....\.txt$/, readdir(DIR));
 		closedir(DIR);
@@ -410,7 +410,7 @@ sub msgcountstr()
 sub messages()
 {
 	my ($context, $mailbox, $folder) = @_;
-	my $path = "/var/spool/asterisk/voicemail/$context/$mailbox/$folder";
+	my $path = "@ASTSPOOLDIR@/voicemail/$context/$mailbox/$folder";
 	if (opendir(DIR, $path)) {
 		my @msgs = sort grep(/^msg....\.txt$/, readdir(DIR));
 		closedir(DIR);
@@ -435,7 +435,7 @@ sub getfields()
 {
 	my ($context, $mailbox, $folder, $msg) = @_;
 	my $fields;
-	if (open(MSG, "</var/spool/asterisk/voicemail/$context/$mailbox/$folder/msg${msg}.txt")) {
+	if (open(MSG, "<@ASTSPOOLDIR@/voicemail/$context/$mailbox/$folder/msg${msg}.txt")) {
 		while(<MSG>) {
 			s/\#.*$//g;
 			if (/^(\w+)\s*\=\s*(.*)$/) {
@@ -560,7 +560,7 @@ _EOH
 	<input name="action" type=submit value="download">
 </td></tr>
 <tr><td colspan=2 align=center>
-<embed width=400 height=40 src="vmail.cgi?action=audio&folder=$folder&mailbox=$mbox&context=$context&password=$passwd&msgid=$msgid&format=$format&dontcasheme=$$.$format" autostart=yes loop=false></embed>
+<embed width=400 height=40 src="vmail?action=audio&folder=$folder&mailbox=$mbox&context=$context&password=$passwd&msgid=$msgid&format=$format&dontcasheme=$$.$format" autostart=yes loop=false></embed>
 </td></tr></table>
 </td></tr>
 </table>
@@ -588,7 +588,7 @@ sub message_audio()
 	}
 	&untaint($format);
 
-	my $path = "/var/spool/asterisk/voicemail/$context/$mailbox/$folder/msg${msgid}.$format";
+	my $path = "@ASTSPOOLDIR@/voicemail/$context/$mailbox/$folder/msg${msgid}.$format";
 
 	$msgid =~ /^\d\d\d\d$/ || die("Msgid Liar ($msgid)!");
 	grep(/^${format}$/, keys %formats) || die("Format Liar ($format)!");
@@ -809,11 +809,11 @@ sub message_rename()
 		die("Invalid old Message<BR>\n");
 	}
 	
-	my $path = "/var/spool/asterisk/voicemail/$context/$mbox/$newfolder";
+	my $path = "@ASTSPOOLDIR@/voicemail/$context/$mbox/$newfolder";
 	$path =~ /^(.*)$/;
 	$path = $1;
 	mkdir $path, 0770;
-	$path = "/var/spool/asterisk/voicemail/$context/$mbox/$oldfolder";
+	$path = "@ASTSPOOLDIR@/voicemail/$context/$mbox/$oldfolder";
 	opendir(DIR, $path) || die("Unable to open directory\n");
 	my @files = grep /^msg${old}\.\w+$/, readdir(DIR);
 	closedir(DIR);
@@ -823,7 +823,7 @@ sub message_rename()
 			$tmp = $1;
 			$oldfile = $path . "/$tmp";
 			$tmp =~ s/msg${old}/msg${new}/;
-			$newfile = "/var/spool/asterisk/voicemail/$context/$mbox/$newfolder/$tmp";
+			$newfile = "@ASTSPOOLDIR@/voicemail/$context/$mbox/$newfolder/$tmp";
 #			print "Renaming $oldfile to $newfile<BR>\n";
 			rename($oldfile, $newfile);
 		}
@@ -884,15 +884,15 @@ sub message_copy()
 		die("Invalid old Message<BR>\n");
 	}
 	
-	my $path = "/var/spool/asterisk/voicemail/$context/$newmbox";
+	my $path = "@ASTSPOOLDIR@/voicemail/$context/$newmbox";
 	$path =~ /^(.*)$/;
 	$path = $1;
 	mkdir $path, 0770;
-	$path = "/var/spool/asterisk/voicemail/$context/$newmbox/INBOX";
+	$path = "@ASTSPOOLDIR@/voicemail/$context/$newmbox/INBOX";
 	$path =~ /^(.*)$/;
 	$path = $1;
 	mkdir $path, 0770;
-	$path = "/var/spool/asterisk/voicemail/$context/$mbox/$oldfolder";
+	$path = "@ASTSPOOLDIR@/voicemail/$context/$mbox/$oldfolder";
 	opendir(DIR, $path) || die("Unable to open directory\n");
 	my @files = grep /^msg${old}\.\w+$/, readdir(DIR);
 	closedir(DIR);
@@ -902,7 +902,7 @@ sub message_copy()
 			$tmp = $1;
 			$oldfile = $path . "/$tmp";
 			$tmp =~ s/msg${old}/msg${new}/;
-			$newfile = "/var/spool/asterisk/voicemail/$context/$newmbox/INBOX/$tmp";
+			$newfile = "@ASTSPOOLDIR@/voicemail/$context/$newmbox/INBOX/$tmp";
 #			print "Copying $oldfile to $newfile<BR>\n";
 			&file_copy($oldfile, $newfile);
 		}
@@ -932,7 +932,7 @@ sub message_delete()
 	} else {
 		die("Invalid Message<BR>\n");
 	}
-	my $path = "/var/spool/asterisk/voicemail/$context/$mbox/$folder";
+	my $path = "@ASTSPOOLDIR@/voicemail/$context/$mbox/$folder";
 	opendir(DIR, $path) || die("Unable to open directory\n");
 	my @files = grep /^msg${msg}\.\w+$/, readdir(DIR);
 	closedir(DIR);
@@ -968,7 +968,7 @@ sub message_forward()
 	my $txt;
 	$context = &untaint($context);
 	$newmbox = &untaint($newmbox);
-	my $path = "/var/spool/asterisk/voicemail/$context/$newmbox/INBOX";
+	my $path = "@ASTSPOOLDIR@/voicemail/$context/$newmbox/INBOX";
 	if ($msgs[0]) {
 		if (&lock_path($path) == 0) {
 			$msgcount = &msgcount($context, $newmbox, "INBOX");
@@ -1018,7 +1018,7 @@ sub message_delete_or_move()
 	$context = &untaint($context);
 	$mbox = &untaint($mbox);
 	$folder = &untaint($folder);
-	$path = "/var/spool/asterisk/voicemail/$context/$mbox/$folder";
+	$path = "@ASTSPOOLDIR@/voicemail/$context/$mbox/$folder";
 	if ($msgs[0]) {
 		if (&lock_path($path) == 0) {
 			my $msgcount = &msgcount($context, $mbox, $folder);
